// DECLARAÇÃO DE BIBLIOTECAS
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "PIN_CONFIG.h"

// variáveis para os buffer de tx e rx
#define RX_BUFFER_SIZE 10
#define TX_BUFFER_SIZE RX_BUFFER_SIZE

uint8_t RxBuffer[RX_BUFFER_SIZE];
uint8_t RxBufferIndex = 0;

uint8_t TxBuffer[TX_BUFFER_SIZE] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9};
uint8_t TxBufferIndex = 0;

////funcao para inicialização da USART - A CONNFIGURACAO ABAIXO JÁ É FEITA PELA BIBLIOTECA

// void initUSART0 (void)
//{
//   //configurando os clocks necessários
//   CMU_ClockEnable(cmuClock_GPIO, true);
//   CMU_ClockEnable(cmuClock_USART0, true);
//
//   // coonfigurando os pinos p/ SPI
//   GPIO_PinModeSet(USART_PIN_CLK_PORT, USART_PIN_CLK_PIN, gpioModeInput, 1);    // US0_CLK - input -PC8
//   GPIO_PinModeSet(USART_PIN_CS_PORT, USART_PIN_CS_PIN, gpioModeInput, 1);    // US0_CS - input -PC10
//   GPIO_PinModeSet(USART_PIN_MOSI_TX_PORT, USART_PIN_MOSI_TX_PIN, gpioModeInput, 1);    // US0_TX (MOSI) - input -PC9
//   GPIO_PinModeSet(USART_PIN_MISO_RX_PORT, USART_PIN_MISO_RX_PIN, gpioModePushPull, 1); // US0_RX (MISO) - push pull -PC11
//
//   // configurações da usart
//   USART_InitSync_TypeDef config = USART_INITSYNC_DEFAULT;
//   config.master    = false;
//   config.clockMode = usartClockMode0; // clock inativo em 0 no modo transição de subida
//   config.msbf      = true;            // enviando o bit mais significante primeiro
//   config.enable    = usartDisable;    // desabilitando a uart até tudo estar configurado
//   USART_InitSync(USART0, &config);
//   USART0->CTRL |= USART_CTRL_SSSEARLY;
//
//   // definindo a localização dos pinos
//   USART0->ROUTELOC0 = (USART_ROUTELOC0_CLKLOC_LOC11) | // US0_CLK       na localização 11 = PC8 - datasheet pag 195
//                       (USART_ROUTELOC0_CSLOC_LOC12)  | // US0_CS        na localização 12 = PC10 - datasheet pag 195
//                       (USART_ROUTELOC0_TXLOC_LOC14)  | // US0_TX (MOSI) na localização 14 = PC9 - datasheet pag 195
//                       (USART_ROUTELOC0_RXLOC_LOC15);   // US0_RX (MISO)  na localização 15 = PC11 - datasheet pag 195
//   SL_SPIDRV_USART_EXP_TYPE
//   // configurando os pinos
//   USART0->ROUTEPEN = USART_ROUTEPEN_CLKPEN | USART_ROUTEPEN_CSPEN | USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;
//
//   // habilitando USART0
//   USART_Enable(USART0, usartEnable);
// }

void app_init(void)
{
  //  initUSART0();
}

void app_process_action(void)
{
  //  transferindo
  if (USART0->STATUS & USART_STATUS_TXBL)
  {
    USART0->TXDATA = TxBuffer[TxBufferIndex];
    TxBufferIndex += 1;
  }

  //  recebendo
  if (USART0->STATUS & USART_STATUS_RXDATAV)
  {
    RxBuffer[RxBufferIndex] = USART0->RXDATA;
    RxBufferIndex += 1;
  }

  if (TxBufferIndex == TX_BUFFER_SIZE)
  {
    TxBufferIndex = 0;
  }

  if (RxBufferIndex == RX_BUFFER_SIZE)
  {
    //        Rx deve ser 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09
    RxBufferIndex = 0;
  }
}
