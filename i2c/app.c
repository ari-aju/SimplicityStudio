
#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "pin_config.h"

// Defines
#define I2C_ADDRESS 0xE2
#define I2C_ADDRESS_MASK 0xFE // Must match exact I2C_ADDRESS
#define I2C_RXBUFFER_SIZE 10

// Buffers++
uint8_t i2c_txBuffer[] = "Arielli";
uint8_t i2c_txBufferSize = sizeof(i2c_txBuffer);
uint8_t i2c_rxBuffer[I2C_RXBUFFER_SIZE];
uint8_t i2c_rxBufferIndex;

// Transmission flags
volatile bool i2c_rxInProgress;
volatile bool i2c_startTx;

void enableI2cSlaveInterrupts(void)
{
  I2C_IntClear(I2C0, I2C_IFC_ADDR | I2C_IF_RXDATAV | I2C_IFC_SSTOP);
  I2C_IntEnable(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
  NVIC_EnableIRQ(I2C0_IRQn);
}

/**************************************************************************/ /**
                                                                              * @brief  disables I2C interrupts
                                                                              *****************************************************************************/
void disableI2cInterrupts(void)
{
  NVIC_DisableIRQ(I2C0_IRQn);
  I2C_IntDisable(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP);
  I2C_IntClear(I2C0, I2C_IFC_ADDR | I2C_IF_RXDATAV | I2C_IFC_SSTOP);
}

void initI2C(void)
{
  // Using default settings
  I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
  // Use ~400khz SCK
  i2cInit.freq = I2C_FREQ_FAST_MAX;
  // Use 6:3 low high SCK ratio
  i2cInit.clhr = i2cClockHLRAsymetric;

  // Using PC0 (SDA) and PC1 (SCL)
  GPIO_PinModeSet(BSP_I2C_SDA_PORT, BSP_I2C_SDA_PIN, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(BSP_I2C_SCL_PORT, BSP_I2C_SCL_PIN, gpioModeWiredAndPullUpFilter, 1);

  // Enable pins at location 4 as specified in datasheet
  I2C0->ROUTEPEN = I2C_ROUTEPEN_SDAPEN | I2C_ROUTEPEN_SCLPEN;
  I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SDALOC_MASK)) | I2C_ROUTELOC0_SDALOC_LOC0;
  I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SCLLOC_MASK)) | I2C_ROUTELOC0_SCLLOC_LOC0;

  // Initializing the I2C
  I2C_Init(I2C0, &i2cInit);

  // Setting the status flags and index
  i2c_rxInProgress = false;
  i2c_startTx = false;
  i2c_rxBufferIndex = 0;

  // Setting up to enable slave mode
  I2C0->SADDR = I2C_ADDRESS;
  I2C0->SADDRMASK = I2C_ADDRESS_MASK;
  I2C0->CTRL |= I2C_CTRL_SLAVE | I2C_CTRL_AUTOACK | I2C_CTRL_AUTOSN;
  enableI2cSlaveInterrupts();
}

void performI2CTransfer(void)
{
  // Transfer structure
  I2C_TransferSeq_TypeDef i2cTransfer;
  I2C_TransferReturn_TypeDef result;

  // Setting LED to indicate transfer
  GPIO_PinOutSet(BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN);

  // Initializing I2C transfer
  i2cTransfer.addr = I2C_ADDRESS;
  i2cTransfer.flags = I2C_FLAG_WRITE;
  i2cTransfer.buf[0].data = i2c_txBuffer;
  i2cTransfer.buf[0].len = i2c_txBufferSize;
  i2cTransfer.buf[1].data = i2c_rxBuffer;
  i2cTransfer.buf[1].len = I2C_RXBUFFER_SIZE;
  result = I2C_TransferInit(I2C0, &i2cTransfer);

  // Sending data
  while (result == i2cTransferInProgress)
  {
    result = I2C_Transfer(I2C0);
  }

  // Clearing pin to indicate end of transfer
  GPIO_PinOutClear(BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN);
  enableI2cSlaveInterrupts();
}

/**************************************************************************/ /**
  * @brief  Receiving I2C data. Along with the I2C interrupt, it will keep the
   EFM32 in EM1 while the data is received.
  *****************************************************************************/
void receiveI2CData(void)
{
  while (i2c_rxInProgress)
  {
    EMU_EnterEM1();
  }
}

/**************************************************************************/ /**
                                                                              * @brief I2C Interrupt Handler.
                                                                              *        The interrupt table is in assembly startup file startup_efm32.s
                                                                              *****************************************************************************/
void I2C0_IRQHandler(void)
{
  int status;

  status = I2C0->IF;

  if (status & I2C_IF_ADDR)
  {
    // Address Match
    // Indicating that reception is started
    i2c_rxInProgress = true;
    I2C0->RXDATA;
    i2c_rxBufferIndex = 0;

    I2C_IntClear(I2C0, I2C_IFC_ADDR);
  }
  else if (status & I2C_IF_RXDATAV)
  {
    // Data received
    i2c_rxBuffer[i2c_rxBufferIndex] = I2C0->RXDATA;
    i2c_rxBufferIndex++;
  }

  if (status & I2C_IEN_SSTOP)
  {
    // Stop received, reception is ended
    I2C_IntClear(I2C0, I2C_IFC_SSTOP);
    i2c_rxInProgress = false;
    i2c_rxBufferIndex = 0;
  }
}

/***************************************************************************/ /**
                                                                               * @brief GPIO Interrupt handler
                                                                               ******************************************************************************/
void GPIO_EVEN_IRQHandler(void)
{
  // Clear pending
  uint32_t interruptMask = GPIO_IntGet();
  GPIO_IntClear(interruptMask);

  // If RX is not in progress, a new transfer is started
  if (!i2c_rxInProgress)
  {
    disableI2cInterrupts();
    i2c_startTx = true;
  }
}

void app_init(void)
{

  // Enabling clock to the I2C, GPIO, LE
  CMU_ClockEnable(cmuClock_I2C0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Starting LFXO and waiting until it is stable
  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);

  // Configure LED0 and LED1 as output
  GPIO_PinModeSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);
  GPIO_PinModeSet(BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN, gpioModePushPull, 0);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

  initI2C();
}

void app_process_action(void)
{
  if (i2c_rxInProgress)
  {
    // Receiving data
    receiveI2CData();
  }
  else if (i2c_startTx)
  {
    // Transmitting data
    performI2CTransfer();
    // Transmission complete
    i2c_startTx = false;
  }

  // Forever enter EM2. The RTC or I2C will wake up the EFM32
  EMU_EnterEM2(false);
}
