
//DECLARAÇÃO DAS BIBLIOTECAS

#include <sl_udelay.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "pin_config.h"
#include "em_letimer.h"

// freq de saída pwm
#define PWM_FREQ 1

// Duty cycle %
int DUTY_CYCLE= 5;

// LETIMER0 frequencia
#define LETIMER0_FREQ CMU_ClockFreqGet(cmuClock_LETIMER0)

//Funcao para ininicar o Letiemr
void initLETIMER(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

  // Definindo o clock para as interfaces LE
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Escolhendo LFXO para o LETIMER
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  // Recarregar COMP0 em underflow, pulsar saída e rodar repetidamente
  letimerInit.comp0Top = true;
  letimerInit.ufoa0 = letimerUFOAPwm;
  letimerInit.repMode = letimerRepeatFree;
  letimerInit.topValue = LETIMER0_FREQ / PWM_FREQ;

  //O REP0 != 0 para PWM
  LETIMER_RepeatSet(LETIMER0, 0, 1);

  // Config COMP1 para controlar o duty cycle
  LETIMER_CompareSet(LETIMER0, 1,
       CMU_ClockFreqGet(cmuClock_LETIMER0) * DUTY_CYCLE / (PWM_FREQ * 100));

  // habilita a saída LETIMER0 no pino PF4 (Rota 28)
  LETIMER0->ROUTEPEN |=  LETIMER_ROUTEPEN_OUT0PEN;
  LETIMER0->ROUTELOC0 |= LETIMER_ROUTELOC0_OUT0LOC_LOC28;

  // inicializa letimer
  LETIMER_Init(LETIMER0, &letimerInit);
}

void app_init(void)
{
  EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
  EMU_DCDCInit(&dcdcInit);

  CMU_ClockEnable(cmuClock_GPIO, true); //habilitando o clock da GPIO

  //configurando o pino do LED
  GPIO_PinModeSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);

  initLETIMER();//iniciando Letimer


}

//função de loop
void app_process_action(void)
{

}
