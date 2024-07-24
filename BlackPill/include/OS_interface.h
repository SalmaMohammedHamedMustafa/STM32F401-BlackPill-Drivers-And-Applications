/*
 * OS_interface.h
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Period,u8 Copy_u8FirstDelay,void (*TFptr)(void));
void OS_voidStart();
void Scheduler();



#endif /* OS_INTERFACE_H_ */
