// DECLARAÇÃO DE BIBLIOTECAS
#include <stdio.h>
#include "sl_iostream_init_usart_instances.h"
#include "sl_app_log.h"

// função de configuração
void app_init(void)
{
}

// função loop()
void app_process_action(void)
{
  // 2 tipos de print:
  sl_iostream_printf(sl_iostream_USART0_handle, "Hello ");
  printf("World!\n\r");
}
