/*
 * SYSCFG_interface.h
 *
 *  Created on: Feb 24, 2024
 *      Author: salma
 */

#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_

/************************EXTI****************/
#define EXTIPinA 0b0000
#define EXTIPinB 0b0001
#define EXTIPinC 0b0010

void SYSCFG_EXTISetPin(u8 Copy_u8LineNo,u8 Copy_u8Pin);


#endif /* SYSCFG_INTERFACE_H_ */
