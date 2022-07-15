// DECLARAÇÃO DAS BIBLIOTECAS
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_ldma.h"

// canais DMA
#define LDMA_CHANNEL 0
#define LDMA_CH_MASK 1 << LDMA_CHANNEL

// tamanho do buffer p/ transferencia de memoria
#define BUFFER_SIZE 4

// numeros de elementos
// envio total = BUFFER_SIZE * NUM_SETS
#define NUM_ITERATIONS 4

// contador
#define LOOP_COUNT NUM_ITERATIONS - 1

// Lista vinculada do descritor para transferência LDMA
LDMA_Descriptor_t descLink;

// buffer p/ transferencia de memoria
uint32_t srcBuffer[BUFFER_SIZE];
uint32_t dstBuffer[NUM_ITERATIONS][BUFFER_SIZE];

// Funcao p/ transferência a cada interrupção
void LDMA_IRQHandler(void)
{
  uint32_t pending;

  // lendo as interrupções
  pending = LDMA_IntGet();

  // limpando as interrupções
  LDMA_IntClear(pending);

  // verificando erros
  if (pending & LDMA_IF_ERROR)
  {
    // loop de erro
    while (1)
      ;
  }

  // iniciando próxima transferência
  LDMA->SWREQ |= LDMA_CH_MASK;
}

void initLdma(void)
{
  uint32_t i, j;

  // iniciando os buffer
  for (i = 0; i < BUFFER_SIZE; i++)
  {
    srcBuffer[i] = i;
    for (j = 0; j < NUM_ITERATIONS; j++)
    {
      dstBuffer[j][i] = 0;
    }
  }

  LDMA_Init_t init = LDMA_INIT_DEFAULT;
  LDMA_Init(&init);

  // configuração de transferência periférica em loop
  LDMA_TransferCfg_t periTransferTx = LDMA_TRANSFER_CFG_MEMORY_LOOP(LOOP_COUNT);

  // descritor para transferencia e loop
  descLink = (LDMA_Descriptor_t)LDMA_DESCRIPTOR_LINKREL_M2M_WORD(&srcBuffer, 0, BUFFER_SIZE, 0);

  descLink.xfer.blockSize = ldmaCtrlBlockSizeUnit4;   // tamanho do bloco = 4
  descLink.xfer.reqMode = ldmaCtrlReqModeBlock;       // modo de requisição = bloco
  descLink.xfer.doneIfs = true;                       // habilitando interrupção
  descLink.xfer.structReq = false;                    // disabilitando requisições automáticas
  descLink.xfer.decLoopCnt = 1;                       // habilitando loop
  descLink.xfer.dstAddrMode = ldmaCtrlSrcAddrModeRel; // cada transferencia usa o destino da última transferência realizada
  descLink.xfer.link = 0;                             // fim da lista

  // iniciando transferencia
  LDMA_StartTransfer(LDMA_CHANNEL, (void *)&periTransferTx, (void *)&descLink);

  // iniciando a transferencia para dstBuffer
  LDMA->CH[LDMA_CHANNEL].DST = (uint32_t)&dstBuffer;

  // enviando requisição de software
  LDMA->SWREQ |= LDMA_CH_MASK;
}

void app_init(void)
{
  EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
  EMU_DCDCInit(&dcdcInit);

  // chamando a funcao p/ iniciar ldma
  initLdma();
}

// funcao de loop
void app_process_action(void)
{

}
