/**
 *EXTI
 *
 * @author Salma Mohammed Hamed
 * @date  16 Feb 2024
 * @version V01
 *
*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void EXTI_voidInit();
void EXTI_voidenableEXTI(u8 Copy_u8Line);
void EXTI_voidDisableEXTI(u8 Copy_u8Line);
void EXTI_voidSwTrigger(u8 Copy_u8Line);
void EXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);

void EXTI_vidSetCallBack (u8 copy_u8Line, void (*ptr) (void));

#endif
