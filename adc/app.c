//DECLARAÇÃO DAS BIBLIOTECAS
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_adc.h"

//DECLARAÇÃO DAS VARIÁVEIS
#define adcFreq   16000000
volatile uint32_t sample;
volatile uint32_t millivolts;

//FUNÇÃO DE INIALIZAÇÃO DO ADC
void initADC (void)
{
  // Habilitando clock ADC
  CMU_ClockEnable(cmuClock_ADC0, true);

  //declarando as variáveis de inicialização
  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;

  // modificando as instruções
  init.prescale = ADC_PrescaleCalc(adcFreq, 0); // Iniciando com máximo clock

  initSingle.diff       = false;        // single ended
  initSingle.reference  = adcRefVDD;    // referência de 3.3V
  initSingle.resolution = adcRes12Bit;  // resolução de 12-bit
  initSingle.acqTime    = adcAcqTime4;  // definir o tempo de aquisição para atender ao requisito mín

  // Selecionando a entrada ADC.
  initSingle.posSel = adcPosSelAPORT3XCH12; //PA4
  init.timebase = ADC_TimebaseCalc(0);

  ADC_Init(ADC0, &init);
  ADC_InitSingle(ADC0, &initSingle);
}

//função de configuração
void app_init(void)
{
//chamando a função p/ ADC
  initADC();
}

//função de loop
void app_process_action(void)
{

  while (1)
  {
      // Iniciando a conversão
          ADC_Start(ADC0, adcStartSingle);

          // Realizando a conversão
          while(!(ADC0->STATUS & _ADC_STATUS_SINGLEDV_MASK));

          // Resultado da conversão
          sample = ADC_DataSingleGet(ADC0);

          //Calculando a tensão em mV
          millivolts = (sample * 3300) / 4096;
  }
}
