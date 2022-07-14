//DECLARAÇÃO DAS BIBLIOTECAS
#include <sl_udelay.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "pin_config.h"

//função de configuração
void app_init(void)
{
  //habilitando o clock da GPIO
  CMU_ClockEnable(cmuClock_GPIO, true);

  //configurando o pino do LED
  GPIO_PinModeSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0);

}

//função de loop
void app_process_action(void)
{
  GPIO_PinOutSet(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN); //ligando LED

  sl_udelay_wait(500000); //atraso de meio segundo

  GPIO_PinOutClear(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN); //desligando LED

  sl_udelay_wait(500000); //atraso de meio segundo
}
