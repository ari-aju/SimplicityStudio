//DECLARAÇÃO DAS BIBLIOTECAS
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_idac.h"
#include "em_emu.h"
#include "em_vdac.h"

// canal de saída VDAC
#define CHANNEL_NUM 0

//FUNÇÃO DE INIALIZAÇÃO DO Idac
void initIdac(void)
{
  // Habilitando clock Idac
  CMU_ClockEnable(cmuClock_IDAC0, true);

  // Inicializando IDAC
  IDAC_Init_TypeDef init = IDAC_INIT_DEFAULT;
  init.outMode = idacOutputAPORT1XCH14; //Definindo a porta IDAC PA6
  IDAC_Init(IDAC0, &init);

  // Escolhendo a corrente de saída como 2uA
  IDAC_RangeSet(IDAC0, idacCurrentRange1);
  IDAC_StepSet(IDAC0, 4);

  // Habilitando os enables
  IDAC_OutEnable(IDAC0, true);
  IDAC_Enable(IDAC0, true);
}

//FUNÇÃO DE INIALIZAÇÃO DO Vdac
void initVdac(void)
{
   // Habilitando clock Vdac
  CMU_ClockEnable(cmuClock_VDAC0, true);

   //Inicializando VDAC
   VDAC_Init_TypeDef        init        = VDAC_INIT_DEFAULT; //config default
   VDAC_InitChannel_TypeDef initChannel = VDAC_INITCHANNEL_DEFAULT;
  // VDAC clock source for asynchronous mode is 12 MHz internal VDAC oscillator
  init.asyncClockMode = true;

  // calculando o valor de clock prescaler p/ resultar em um ckock VDAC de 1 MHz
  init.prescaler = VDAC_PrescaleCalc(1000000, false, 0);

  // definindo uma referência interna de 1.25V de ruído baixo
  init.reference = vdacRef1V25Ln;

  //período a cada 8 ciclos de clock
  init.refresh = vdacRefresh8;

  // modo de saída como sample/off
  initChannel.sampleOffMode = true;

  // Set the trigger mode to SWREFRESH so that the internal timer or a software
  // trigger will trigger the VDAC conversion
  initChannel.trigMode = vdacTrigModeSwRefresh;

  // Inicializando o VDAC e o canal VDAC
  VDAC_Init(VDAC0, &init);
  VDAC_InitChannel(VDAC0, &initChannel, CHANNEL_NUM);

  // Habilitando o VDAC
  VDAC_Enable(VDAC0, CHANNEL_NUM, true);
}

void app_init(void)
{
  // Iniciando o regulador DCDC com valores default
    EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
    EMU_DCDCInit(&dcdcInit);

    //chamando as funções de ADC
  initIdac();
  initVdac();
}


void app_process_action(void)
{

  //calculando o calor de saída de 12-bit output para 0.5 V
  uint32_t vdacValue = (uint32_t)((0.5* 4095) / 1.25);

    // Definindo o valor de saída para o registro de dados VDAC
    VDAC_ChannelOutputSet(VDAC0, CHANNEL_NUM, vdacValue);

  while (1) {
      EMU_EnterEM3(false); // FUNÇÃO DE LOOP
    }
}
