/*
 * UART_program.c
 *
 *  Created on: Mar 9, 2024
 *      Author: salma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit()
{
	/*set baud rate*/
	UART -> BRR = UART_BRR_VALUE;
	/*clear statues registers*/
	UART -> SR = 0;
	/*over sampling by 16*/
	CLR_BIT(UART -> CR1, 15);
	/*1 Start bit, 8 Data bits, n Stop bit*/
	CLR_BIT(UART -> CR1,12);
#if UART_PARITY_ENABLE == enable
	SET_BIT(UART -> CR1 ,10);
#if UART_PARITY_MODE ==EvenParity
	CLR_BIT(UART -> CR1 ,9);
#elif UART_PARITY_MODE== OddParity
	SET_BIT(UART -> CR1 ,9);
#endif
#elif UART_PARITY_ENABLE == disable

#endif
	/*interrupts*/


	/*Transmitter enable*/
	SET_BIT(UART -> CR1 ,3);
	/*Receiver enable*/
	SET_BIT(UART -> CR1 ,2);
	/*UART enable*/
	SET_BIT(UART -> CR1 ,13);
}
void UART_voidTransmit(u8 *Copy_u8Data)
{
	/*clear the flag*/
	CLR_BIT(UART -> SR, 6);
	/*wait transmission to complete*/
	while (get_bit(UART -> SR, 6)==0);
	/*Transmitter enable*/
	SET_BIT(UART -> CR1 ,3);
	UART->DR=*Copy_u8Data;


}
u8 UART_u8Recieve ()
{
	/*wait to receive */
	while(get_bit(UART -> SR, 5)==0);
	return (UART->DR& 0xFF);
}
