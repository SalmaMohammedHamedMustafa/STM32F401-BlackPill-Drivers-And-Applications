/*
 * NVIC_interface.h
 *
 *  Created on: Feb 12, 2024
 *      Author: salma
 */

#ifndef INC_NVIC_INTERFACE_H_
#define INC_NVIC_INTERFACE_H_
#define NVIC_16GROUP_0SUB   0x05FA50300 /**< 16 Priority Levels, No Sub-priority , 4 bits for group*/
#define NVIC_8GROUP_2SUB    0x05FA50400 /**< 8 Priority Levels, 2 Sub-priority Levels, 3 bits for group, 1 for sub group */
#define NVIC_4GROUP_4SUB    0x05FA50500 /**< 4 Priority Levels, 4 Sub-priority Levels 2 bits for group, 2 for sub group*/
#define NVIC_2GROUP_8SUB    0x05FA50600 /**< 2 Priority Levels, 8 Sub-priority Levels 1 bits for group, 3 for sub group*/
#define NVIC_0GROUP_16SUB   0x05FA50700 /**< No Grouping, 16 Sub-priority Levels 0 bits for group, 4 for sub group*/

#define NVIC_WWDG_IRQn               0   /**< WWDG Window Watchdog interrupt */
#define NVIC_PVD_IRQn                1   /**< PVD PVD through EXTI Line detection interrupt */
#define NVIC_TAMPER_IRQn             2   /**< TAMPER Tamper interrupt */
#define NVIC_RTC_IRQn                3   /**< RTC RTC global interrupt */
#define NVIC_FLASH_IRQn              4   /**< FLASH Flash global interrupt */
#define NVIC_RCC_IRQn                5   /**< RCC RCC global interrupt */
#define NVIC_EXTI0_IRQn              6   /**< EXTI0 EXTI Line0 interrupt */
#define NVIC_EXTI1_IRQn              7   /**< EXTI1 EXTI Line1 interrupt */
#define NVIC_EXTI2_IRQn              8   /**< EXTI2 EXTI Line2 interrupt */
#define NVIC_EXTI3_IRQn              9   /**< EXTI3 EXTI Line3 interrupt */
#define NVIC_EXTI4_IRQn              10  /**< EXTI4 EXTI Line4 interrupt */
#define NVIC_DMA1_Channel1_IRQn      11  /**< DMA1_Channel1 DMA1 Channel1 global interrupt */
#define NVIC_DMA1_Channel2_IRQn      12  /**< DMA1_Channel2 DMA1 Channel2 global interrupt */
#define NVIC_DMA1_Channel3_IRQn      13  /**< DMA1_Channel3 DMA1 Channel3 global interrupt */
#define NVIC_DMA1_Channel4_IRQn      14  /**< DMA1_Channel4 DMA1 Channel4 global interrupt */
#define NVIC_DMA1_Channel5_IRQn      15  /**< DMA1_Channel5 DMA1 Channel5 global interrupt */
#define NVIC_DMA1_Channel6_IRQn      16  /**< DMA1_Channel6 DMA1 Channel6 global interrupt */
#define NVIC_DMA1_Channel7_IRQn      17  /**< DMA1_Channel7 DMA1 Channel7 global interrupt */
#define NVIC_ADC1_2_IRQn             18  /**< ADC1_2 ADC1 and ADC2 global interrupt */
#define NVIC_CAN1_TX_IRQn            19  /**< CAN1_TX CAN1 TX interrupts */
#define NVIC_CAN1_RX0_IRQn           20  /**< CAN1_RX0 CAN1 RX0 interrupts */
#define NVIC_CAN1_RX1_IRQn           21  /**< CAN1_RX1 CAN1 RX1 interrupt */
#define NVIC_CAN1_SCE_IRQn           22  /**< CAN1_SCE CAN1 SCE interrupt */
#define NVIC_EXTI9_5_IRQn            23  /**< EXTI9_5 EXTI Line[9:5] interrupts */
#define NVIC_TIM1_BRK_IRQn           24  /**< TIM1_BRK TIM1 Break interrupt */
#define NVIC_TIM1_UP_IRQn            25  /**< TIM1_UP TIM1 Update interrupt */
#define NVIC_TIM1_TRG_COM_IRQn       26  /**< TIM1_TRG_COM TIM1 Trigger and Commutation interrupts */
#define NVIC_TIM1_CC_IRQn            27  /**< TIM1_CC TIM1 Capture Compare interrupt */

void NVIC_Init();
void NVIC_voidEnableInterrupt(u8 copy_u8IntNum);
void NVIC_voidDisableInterrupt(u8 copy_u8IntNum);
void NVIC_voidSetPendingFlag(u8 copy_u8IntNum);
void NVIC_voidClearPendingFlag(u8 copy_u8IntNum);
u8 NVIC_voidGetActiveFlag(u8 copy_u8IntNum);
void NVIC_voidSetPriority(s8 copy_s8IntID, u8 copy_u8GroupPriorty, u8 copy_u8Subpriority );
#endif /* INC_NVIC_INTERFACE_H_ */
