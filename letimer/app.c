
// DECLARAÇÃO DAS BIBLIOTECAS
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "pin_config.h"
#include "em_letimer.h"

// Inicialização do TImer de Baixa energia (le)
void initLetimer(void)
{
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT; // config default

  // Habilitando o clock para os módulos de interface LE
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Definindo LFXO para o LETIMER
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  // Recarregando COMP0 em underflow, setando a saída, e rodando repetidas vezes
  letimerInit.comp0Top = true;
  letimerInit.ufoa0 = letimerUFOAToggle;
  letimerInit.repMode = letimerRepeatFree;
  letimerInit.enable = false;
  letimerInit.topValue = 32000;

  // Precisa de REP0 != 0 para rodar até o proximo evento
  LETIMER_RepeatSet(LETIMER0, 0, 1);

  // Habilitando a saída LETIMER0 no PF4 (Rota 28)
  LETIMER0->ROUTEPEN |= LETIMER_ROUTEPEN_OUT0PEN;
  LETIMER0->ROUTELOC0 |= LETIMER_ROUTELOC0_OUT0LOC_LOC28;

  // Inicializando LETIMER
  LETIMER_Init(LETIMER0, &letimerInit);

  // comparar na inicializacao da contagem de intervalo
  LETIMER_Enable(LETIMER0, true);
}

// funcao de setup
void app_init(void)
{

  CMU_ClockEnable(cmuClock_GPIO, true); // habilitando o clock da GPIO

  // configurando o pino do LED
  GPIO_PinModeSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);

  // iniciando o Letimer
  initLetimer();
}

// Funcao loop
void app_process_action(void)
{
}
