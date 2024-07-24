/*
 * UART_interface.h
 *
 *  Created on: Mar 9, 2024
 *      Author: salma
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#define EvenParity 1
#define OddParity  2
void UART_voidInit();
void UART_voidTransmit(u8 *Copy_u8Data);
u8 UART_u8Recieve ();


#endif /* UART_INTERFACE_H_ */
