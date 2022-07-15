//DECLARACAO DE BIBLIOTECAS
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_LETIMER.h"
#include "em_chip.h"

#define BUFFER_SIZE 80
char buffer[BUFFER_SIZE];

USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
char welcome_string[] = "Olá! Arielli aqui <3\r\f";
int i,j,z=0;




#define TOP_VALUE 32000 //frequencia

void LETIMER0_IRQHandler(void)
{
  // Acknowledge the interrupt
  uint32_t flags = LETIMER_IntGet(LETIMER0);
  LETIMER_IntClear(LETIMER0, flags);
  welcome_string[20] = String(z);
      z++;

  // transmitindo a mensagem
    for (i = 0 ; welcome_string[i] != 0; i++)
    {
      USART_Tx(USART0, welcome_string[i]);
    }


}



//Funcao para ininicar o Letiemr
void initLETIMER(void)
{
  LETIMER_Init_TypeDef LETIMERInit = LETIMER_INIT_DEFAULT;

  // Definindo o clock para as interfaces LE
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Escolhendo LFXO para o LETIMER
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  // Recarregar COMP0 em underflow, pulsar saída e rodar repetidamente
  LETIMERInit.comp0Top = true;
  LETIMERInit.ufoa0 = LETIMERUFOAToggle;
  LETIMERInit.repMode = LETIMERRepeatFree;
  LETIMERInit.enable = false;
  LETIMERInit.topValue = TOP_VALUE;

  //O REP0 != 0 para pulsar em underflow
  LETIMER_RepeatSet(LETIMER0, 0, 1);

  // habilita a saída LETIMER0 no pino PF4 (Rota 28)
  LETIMER0->ROUTEPEN |=  LETIMER_ROUTEPEN_OUT0PEN;
  LETIMER0->ROUTELOC0 |= LETIMER_ROUTELOC0_OUT0LOC_LOC28;

  // inicializa LETIMER
  LETIMER_Init(LETIMER0, &LETIMERInit);
  LETIMER_Enable(LETIMER0,true);

  // Enable LETIMER0 interrupts for Capture/Compare on channel 0
   LETIMER_IntEnable(LETIMER0, LETIMER_IEN_CC0);
   NVIC_EnableIRQ(LETIMER0_IRQn);
}


void app_init(void)
{

  // Coonfigurando clock para  GPIO e USART0
   CMU_ClockEnable(cmuClock_GPIO, true);
   CMU_ClockEnable(cmuClock_USART0, true);

   //configurando os pinos TX e RX
   GPIO_PinModeSet(gpioPortA, 1, gpioModeInput, 0);
   GPIO_PinModeSet(gpioPortA, 0, gpioModePushPull, 1);

   // Iniciando a USART assíncrona nos pinos
   USART_InitAsync(USART0, &init);
   USART0->ROUTELOC0 = USART_ROUTELOC0_RXLOC_LOC0 | USART_ROUTELOC0_TXLOC_LOC0;
   USART0->ROUTEPEN |= USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;

}

void app_process_action(void)
{
  // Lendo a UART
         for (i = 0; i < BUFFER_SIZE - 1 ; i++ )
         {
           buffer[i] = USART_Rx(USART0);
           if (buffer[i] == '\r')
           {
             break; //saindo do loop for caso a mensagem recebida chegue ao fim
           }
         }

         // ECO -> retransmitindo a mensagem recebida
         for (j = 0; j < i ; j ++ )
         {
           USART_Tx(USART0, buffer[j]);
         }
         USART_Tx(USART0, '\r');
         USART_Tx(USART0, '\f');

         initLETIMER();
}
