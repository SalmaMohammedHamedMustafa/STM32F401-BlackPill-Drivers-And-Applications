/*
 * GPIO_interface.h
 *
 *  Created on: Feb 23, 2024
 *      Author: salma
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
/***********************************< THE AVAILABLE PORTS IN STM32F103C8 ***********************************/
#define GPIO_PORTA					    0
#define GPIO_PORTB					    1
#define GPIO_PORTC					    2
/***********************************< THE AVAILABLE PINS IN STM32F103C8 ***********************************/
#define GPIO_PIN0						0
#define GPIO_PIN1        				1
#define GPIO_PIN2        				2
#define GPIO_PIN3        				3
#define GPIO_PIN4        				4
#define GPIO_PIN5        				5
#define GPIO_PIN6        				6
#define GPIO_PIN7        				7
#define GPIO_PIN8        				8
#define GPIO_PIN9        				9
#define GPIO_PIN10       				10
#define GPIO_PIN11       				11
#define GPIO_PIN12       				12
#define GPIO_PIN13       				13
#define GPIO_PIN14       				14
#define GPIO_PIN15       				15
/***************Direction**********************/
#define input  0b00
#define output 0b01
/****************output type********************/
#define PushPull  0
#define OpenDrain 1
/****************Output Speed*******************/
#define LowSpeed      0b00
#define MediumSpeed   0b01
#define HighSpeed     0b10
#define VeryHighSpeed 0b11
/*****************pullup/down**************************/
#define PullUp   0b01
#define PullDown 0b10
#define Floating 0b00

void GPIO_voidSetPinDirOutput(u8 Copy_PORT, u8 Copy_PIN,u8 Copy_Type,u8 Copy_Speed);
void GPIO_voidSetPinValue(u8 Copy_PORT,u8 Copy_PIN, u8 Copy_Value);
void GPIO_voidSetPinDirInput(u8 Copy_PORT, u8 Copy_PIN,u8 Copy_PullUpDir);
u8  GPIO_u8GetPinValue(u8 Copy_PORT, u8 Copy_PIN);
void GPIO_voidSetPortValue(u8 Copy_PORT ,u16 Copy_Value);
void GPIO_voidSetPortDir(u8 Copy_PORT,u32 Copy_DirL,u32 Copy_DirH);
u8 GPIO_u8LockPin(u8 Copy_PORT, u8 Copy_PIN);


#endif /* GPIO_INTERFACE_H_ */
