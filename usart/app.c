//DECLARACAO DE BIBLIOTECAS
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_chip.h"

#define BUFFER_SIZE 80
char buffer[BUFFER_SIZE];

USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
char welcome_string[] = "Hello World!\r\f";
int i,j;

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

   // transmitindo a mensagem
     for (i = 0 ; welcome_string[i] != 0; i++)
     {
       USART_Tx(USART0, welcome_string[i]);
     }

     while (1)
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
     }

}

void app_process_action(void)
{

}
