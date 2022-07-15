// DECLARACAO DE BIBLIOTECAS
#include <sl_udelay.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "pin_config.h"
#include "em_timer.h"

// Frequencia do PWM
#define PWM_FREQ 1000

// dutycycle %
static volatile int dutyCyclePercent = 0;

int i = 5; // variavel auxiliar p/ duty cycle

// Funcao p/ atualizar Timer
void TIMER0_IRQHandler(void)
{
  // incrementando/decrementando o dutycycle
  dutyCyclePercent += i;

  // atualizando interrupcao
  uint32_t flags = TIMER_IntGet(TIMER0);
  TIMER_IntClear(TIMER0, flags);

  // atualizando dutycycle
  TIMER_CompareBufSet(TIMER0, 0, (TIMER_TopGet(TIMER0) * dutyCyclePercent) / 100);

  // invertendo o valor de i caso o dutycycle atinja os valores máx e min
  if (dutyCyclePercent > 100 || dutyCyclePercent < 5)
    i = -i;

  sl_udelay_wait(100000); // delay
}

// Funcao p/ iniciar Timer
void initTimer(void)
{
  // habilitando clock p/ o TIMER0
  CMU_ClockEnable(cmuClock_TIMER0, true);

  // Configurar o TIMER0 para comparar a saida
  //  Use PWM mode, which sets output on overflow and clears on compare events
  TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
  timerCCInit.mode = timerCCModePWM;
  TIMER_InitCC(TIMER0, 0, &timerCCInit);

  // habilita a saída TIMER0 no pino PF4 (Rota 28)
  TIMER0->ROUTELOC0 |= TIMER_ROUTELOC0_CC0LOC_LOC28;
  TIMER0->ROUTEPEN |= TIMER_ROUTEPEN_CC0PEN;

  // configurando o PWM no timer
  TIMER_TopSet(TIMER0, CMU_ClockFreqGet(cmuClock_TIMER0) / PWM_FREQ);

  // configurando o dutycycle no Timer
  TIMER_CompareSet(TIMER0, 0, (TIMER_TopGet(TIMER0) * dutyCyclePercent) / 100);

  // iniciando o timer
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
  TIMER_Init(TIMER0, &timerInit);

  // habilitando a atualização do Timer
  TIMER_IntEnable(TIMER0, TIMER_IEN_CC0);
  NVIC_EnableIRQ(TIMER0_IRQn);
}

void app_init(void)
{
  EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
  EMU_DCDCInit(&dcdcInit);

  CMU_ClockEnable(cmuClock_GPIO, true); // habilitando o clock da GPIO

  // configurando o pino do LED
  GPIO_PinModeSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);

  initTimer();
}

void app_process_action(void)
{
}
