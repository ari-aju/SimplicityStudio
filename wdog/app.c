//DECLARACAO DE BIBLIOTECAS

#include <sl_udelay.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_rmu.h"
#include "em_gpio.h"
#include "pin_config.h"
#include "em_wdog.h"
#include "em_system.h"



// variavel global
unsigned long resetCause;

void initWDOG(void)
{
  // habilitando clock para LE
  CMU_ClockEnable(cmuClock_HFLE, true);

  // configuracoes p/ iniciar watchdog
  WDOG_Init_TypeDef wdogInit = WDOG_INIT_DEFAULT;
  wdogInit.debugRun = true;
  wdogInit.em3Run = true;
  wdogInit.clkSel = wdogClkSelULFRCO;
  wdogInit.perSel = wdogPeriod_2k; // clock de 2049 ciclos de 1kHz clock  ~ periodo de 2 segundos

  // iniciando o clock
  WDOGn_Init(DEFAULT_WDOG, &wdogInit);
}

void app_init(void)
{

  CMU_ClockEnable(cmuClock_GPIO, true); //habilitando o clock da GPIO

  //configurando o pino do LED
  GPIO_PinModeSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);

  // Configure PB0 as input
  GPIO_PinModeSet(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, gpioModeInputPull, 1);

  // Init DCDC regulator with kit specific parameters
    #if defined( _EMU_DCDCCTRL_MASK )
    EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
    EMU_DCDCInit(&dcdcInit);
    #endif


    // Store the cause of the last reset, and clear the reset cause register
    resetCause = RMU_ResetCauseGet();
    // Clear Reset causes so we know which reset occurs the next time
    RMU_ResetCauseClear();

    // Setup SysTick Timer for 1 msec interrupts
    if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) while (1) ;

    // Configure and Initialize the Watchdog timer
    initWDOG();


}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{


  // Check if Power on Reset (POR) triggered the last reset
  if (resetCause & RMU_RSTCAUSE_WDOGRST)
  {
    // Turn LED0 and LED1 ON
    GPIO_PinOutSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN);
    while(1); //Stay here
  }

  // Enter loop, and feed the WDOG
  while (1)
  {

      // Do not feed the WDOG if PB0 is pressed
         while(!(GPIO_PinInGet(BSP_GPIO_PB0_PORT,BSP_GPIO_PB0_PIN)))
         {
           // Enter EM3 while the button is pressed
           // (WDOG will continue running)
           EMU_EnterEM3(true);
         }
  // Feed the watchdog
  WDOGn_Feed(DEFAULT_WDOG);

  // Toggle LED0 and LED1 at 10 kHz
  GPIO_PinOutToggle(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN);
  sl_udelay_wait(100000);
  }

}
