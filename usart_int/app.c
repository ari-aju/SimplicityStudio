// DECLARACAO DE BIBLIOTECAS
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_USART.h"
#include "em_chip.h"
#include "em_emu.h"
#include "pin_config.h"

// tamanho do buffer recebido
#define BUFLEN 80

// buffer recebido
uint8_t buffer[BUFLEN];

// posição atual do buffer
uint32_t inpos = 0;
uint32_t outpos = 0;

// variável auxiliar p/ o while de recebimento de mensagem
bool receive = true;

// FUNCAO DE CONFIGURAÇÃO DOS PINOS
void initGpio(void)
{
  // habilitando clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  // definindo o pino de transmissão - PA0
  GPIO_PinModeSet(USART0_TX_PORT, USART0_TX_PIN, gpioModePushPull, 1);

  // definindo o pino de transmissão - PA0
  GPIO_PinModeSet(USART0_RX_PORT, USART0_RX_PIN, gpioModeInput, 0);
}

// FUNCAO PARA CONFIGURACAO DA USART0
void initUSART0(void)
{
  // habilitando clock
  CMU_ClockEnable(cmuClock_USART0, true);

  // inicializando modo assíncrono (115.2 Kbps, 8N1, nenhum controle flow)
  USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;

  // configura e habilita USART0
  USART_InitAsync(USART0, &init);

  // Habilitando fontes USARTs NVIC
  NVIC_ClearPendingIRQ(USART0_RX_IRQn);
  NVIC_EnableIRQ(USART0_RX_IRQn);
  NVIC_ClearPendingIRQ(USART0_TX_IRQn);
  NVIC_EnableIRQ(USART0_TX_IRQn);

  // Habilitando TX e EX (baseado na localização dos pinos)
  USART0->ROUTELOC0 = USART0_RX_LOC | USART0_TX_LOC;
  USART0->ROUTEPEN |= USART_ROUTEPEN_RXPEN | USART_ROUTEPEN_TXPEN;
}

// FUNCAO PARA RECEBIMENTO DE MENSAGENS
void USART0_RX_IRQHandler(void)
{
  // pega o dado recebido
  buffer[inpos] = USART0->RXDATA;

  // sai do loop apenas se a mensagem for totalmente mapeada
  if ((buffer[inpos] != '\r') && (inpos < BUFLEN))
    inpos++;
  else
    receive = false; // fim da recepção
}

// FUNCAO PARA TRANSMISSAO DE MENSAGENS
void USART0_TX_IRQHandler(void)
{
  // retransmie o dado recebido anteriormente (eco)
  if (outpos < inpos)
    USART0->TXDATA = buffer[outpos++];
  else
  // precisa desabilitar a interrupçaõ de transmissão, se não ela vai ficar acontecendo
  //  mesmo quando não há dado recebido para retransmissão
  {
    receive = true; // Go back into receive when all is sent
    USART_IntDisable(USART0, USART_IEN_TXBL);
  }
}

void app_init(void)
{

  // inicializações
  initGpio();
  initUSART0();
}

void app_process_action(void)
{
  uint32_t i;
  // Limpa o buffer
  for (i = 0; i < BUFLEN; i++)
    buffer[i] = 0;

  // Habilita a interrupção para os dados recebdos pela UART
  USART_IntEnable(USART0, USART_IEN_RXDATAV);

  // aguarda até o fim do processo de recebimento
  while (receive)
    EMU_EnterEM1();

  // Desabilita a interrupção para os dados recebdos pela UART
  USART_IntDisable(USART0, USART_IEN_RXDATAV);

  // Habilita a interrupção para transmissão dos dados
  USART_IntEnable(USART0, USART_IEN_TXBL);

  // aguarda até o fim do processo de transmissão
  while (!receive)
    EMU_EnterEM1();

  // reseta os contadores do buffer
  inpos = outpos = 0;
}
