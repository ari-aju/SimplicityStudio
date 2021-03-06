#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[ADC0]
// [ADC0]$

// $[CMU]
// [CMU]$

// $[DBG]
// DBG SWV on PF2
#define DBG_SWV_PORT                             gpioPortF
#define DBG_SWV_PIN                              2
#define DBG_SWV_LOC                              0

// [DBG]$

// $[ETM]
// [ETM]$

// $[PTI]
// [PTI]$

// $[GPIO]
// [GPIO]$

// $[I2C0]
// I2C0 SCL on PA1
#define I2C0_SCL_PORT                            gpioPortA
#define I2C0_SCL_PIN                             1
#define I2C0_SCL_LOC                             0

// I2C0 SDA on PA0
#define I2C0_SDA_PORT                            gpioPortA
#define I2C0_SDA_PIN                             0
#define I2C0_SDA_LOC                             0

// [I2C0]$

// $[I2C1]
// [I2C1]$

// $[LESENSE]
// [LESENSE]$

// $[LETIMER0]
// [LETIMER0]$

// $[LEUART0]
// [LEUART0]$

// $[LFXO]
// [LFXO]$

// $[MODEM]
// [MODEM]$

// $[PCNT0]
// [PCNT0]$

// $[PCNT1]
// [PCNT1]$

// $[PCNT2]
// [PCNT2]$

// $[PRS.CH0]
// [PRS.CH0]$

// $[PRS.CH1]
// [PRS.CH1]$

// $[PRS.CH2]
// [PRS.CH2]$

// $[PRS.CH3]
// [PRS.CH3]$

// $[PRS.CH4]
// [PRS.CH4]$

// $[PRS.CH5]
// [PRS.CH5]$

// $[PRS.CH6]
// [PRS.CH6]$

// $[PRS.CH7]
// [PRS.CH7]$

// $[PRS.CH8]
// [PRS.CH8]$

// $[PRS.CH9]
// [PRS.CH9]$

// $[PRS.CH10]
// [PRS.CH10]$

// $[PRS.CH11]
// [PRS.CH11]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[USART0]
// [USART0]$

// $[USART1]
// [USART1]$

// $[USART2]
// [USART2]$

// $[USART3]
// [USART3]$

// $[VDAC0]
// [VDAC0]$

// $[WTIMER0]
// [WTIMER0]$

// $[WTIMER1]
// [WTIMER1]$

// $[CUSTOM_PIN_NAME]
#define BSP_I2C_SDA_PORT                         gpioPortA
#define BSP_I2C_SDA_PIN                          0

#define BSP_I2C_SCL_PORT                         gpioPortA
#define BSP_I2C_SCL_PIN                          1

#define BSP_GPIO_LED0_PORT                       gpioPortC
#define BSP_GPIO_LED0_PIN                        7

#define BSP_GPIO_LED1_PORT                       gpioPortF
#define BSP_GPIO_LED1_PIN                        4

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

