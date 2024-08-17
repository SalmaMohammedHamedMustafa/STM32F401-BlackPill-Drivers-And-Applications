/**
 *SysTick
 *
 * @author Salma Mohammed Hamed
 * @date  16 Feb 2024
 * @version V01
 *
*/
#ifndef __STK_INTERFACE_H__
#define __STK_INTERFACE_H__

void STK_Init(void);

void STK_Start(void);

void STK_Stop(void);

void STK_Reset(void);

u32 STK_GetRemainingCounts(void);

u32 STK_GetElapsedCounts(void);

void STK_SetBusyWait(u32 Copy_Microseconds);

void STK_SetDelay(f32 Copy_Milliseconds);

void STK_SetIntervalSingle(u32 Copy_Microseconds, void (*Copy_Callback)(void));

void STK_SetIntervalPeriodic(u32 Copy_Microseconds, void (*Copy_Callback)(void));

#endif /**<  __STK_INTERFACE_H__ */

