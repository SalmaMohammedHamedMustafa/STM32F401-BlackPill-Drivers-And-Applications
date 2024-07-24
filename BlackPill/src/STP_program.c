/*
 * STP_program.c
 *
 *  Created on: Mar 2, 2024
 *      Author: salma
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "STP_interface.h"
#include "STP_config.h"



void STP_voidSendSync(u8 Copy_u8DataToSend)
{
	/*send bit by bit starting from MSB*/
	s8 Local_s8counter;
	u8 Local_u8Bit;
	for (Local_s8counter=7;Local_s8counter>=0;Local_s8counter--)
	{
		Local_u8Bit=GET_BIT(Copy_u8DataToSend,Local_s8counter);
		GPIO_voidSetPinValue(STP_SERIAL_DATA,Local_u8Bit);
		/*shift clk*/
		GPIO_voidSetPinValue(STP_SHIFT_CLK,HIGH);
		STK_SetBusyWait(100);
		GPIO_voidSetPinValue(STP_SHIFT_CLK,Low);
		STK_SetBusyWait(100);
	}
	GPIO_voidSetPinValue(STP_STORAGE_CLK,HIGH);
	STK_SetBusyWait(100);
	GPIO_voidSetPinValue(STP_STORAGE_CLK,Low);
	STK_SetBusyWait(100);
}
