// DECLARACAO DE BIBLIOTECAS
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "pin_config.h"
#include "em_letimer.h"

#define TOP_VALUE 32000 // frequencia

// Funcao para ininicar o Letiemr
void initLetimer(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

  // Definindo o clock para as interfaces LE
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Escolhendo LFXO para o LETIMER
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  // Recarregar COMP0 em underflow, pulsar saída e rodar repetidamente
  letimerInit.comp0Top = true;
  letimerInit.ufoa0 = letimerUFOAToggle;
  letimerInit.repMode = letimerRepeatFree;
  letimerInit.enable = false;
  letimerInit.topValue = TOP_VALUE;

  // O REP0 != 0 para pulsar em underflow
  LETIMER_RepeatSet(LETIMER0, 0, 1);

  // habilita a saída LETIMER0 no pino PF4 (Rota 28)
  LETIMER0->ROUTEPEN |= LETIMER_ROUTEPEN_OUT0PEN;
  LETIMER0->ROUTELOC0 |= LETIMER_ROUTELOC0_OUT0LOC_LOC28;

  // inicializa letimer
  LETIMER_Init(LETIMER0, &letimerInit);
  LETIMER_Enable(LETIMER0, true);
}

// funcao de config
void app_init(void)
{

  CMU_ClockEnable(cmuClock_GPIO, true); // habilitando o clock da GPIO

  // configurando o pino do LED
  GPIO_PinModeSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);

  initLetimer(); // iniciando Letimer
}

// funcao de loop
void app_process_action(void)
{
}
