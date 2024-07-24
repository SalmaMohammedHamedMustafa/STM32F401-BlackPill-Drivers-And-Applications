/**
 *Reset and Clock Control (RCC) peripheral.
 *
 * @author Salma Mohammed Hamed
 * @date 1 Feb 2024
 * @version V01
 *
*/
#include "STD_TYPES.h"
#ifndef __RCC_INTERFACE_H__
#define __RCC_INTERFACE_H__

/********************************< Bus Architecture options ********************************/
#define RCC_AHB 				    0
#define RCC_APB1				    1
#define RCC_APB2				    2
/********************************< AHB PERIPHERAL CLOCK ENABLE REGISTER  ********************************/
#define RCC_AHB_DMA1_EN            0
#define RCC_AHB_DMA2_EN            1
#define RCC_AHB_SRAM_EN            2   
#define RCC_AHB_FLITF_EN           4
#define RCC_AHB_CRCE_EN            6
#define RCC_AHB_FSMC_EN            8
#define RCC_AHB_SDIO_EN            10
/********************************< APB1 PERIPHERAL CLOCK ENABLE REGISTER ********************************/
#define RCC_APP1_TIM2_EN           0                      
#define RCC_APP1_TIM3_EN           1
#define RCC_APP1_TIM4_EN           2
#define RCC_APP1_TIM5_EN           3
#define RCC_APP1_TIM6_EN           4
#define RCC_APP1_TIM7_EN           5
#define RCC_APP1_TIM12_EN          6
#define RCC_APP1_TIM13_EN          7
#define RCC_APP1_TIM14_EN          8
#define RCC_APP1_WWDG_EN           11
#define RCC_APP1_SPI2_EN           14
#define RCC_APP1_SPI3_EN           15
#define RCC_APP1_USART2_EN         17
#define RCC_APP1_USART3_EN         18
#define RCC_APP1_UART4_EN          19
#define RCC_APP1_UART5_EN          20
#define RCC_APP1_I2C1_EN           21
#define RCC_APP1_I2C2_EN           22
#define RCC_APP1_USB_EN            23
#define RCC_APP1_CAN_EN            25
#define RCC_APP1_BKP_EN            27
#define RCC_APP1_PWR_EN            28
#define RCC_APP1_DAC_EN            29
/********************************< APB2 PERIPHERAL CLOCK ENABLE REGISTER ********************************/
#define RCC_APP2_AFIO_EN           0
#define RCC_APP2_IOPA_EN           2
#define RCC_APP2_IOPB_EN           3
#define RCC_APP2_IOPC_EN           4
#define RCC_APP2_IOPD_EN			5
#define RCC_APP2_IOPE_EN			6
#define RCC_APP2_IOPF_EN			7
#define RCC_APP2_IOPG_EN			8
#define RCC_APP2_ADC1_EN           9
#define RCC_APP2_ADC2_EN           10
#define RCC_APP2_TIM1_EN           11
#define RCC_APP2_SPI1_EN           12
#define RCC_APP2_TIM8_EN           13
#define RCC_APP2_USART1_EN         14
#define RCC_APP2_ADC3_EN           15
#define RCC_APP2_TIM9_EN           19
#define RCC_APP2_TIM10_EN          20
#define RCC_APP2_TIM11_EN          21
void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_PeriphId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_PeriphId);
#endif /**< __RCC_INTERFACE_H__ */
