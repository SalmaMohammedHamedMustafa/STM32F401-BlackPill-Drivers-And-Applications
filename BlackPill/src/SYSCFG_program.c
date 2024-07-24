/*
 * SYSCFG_program.c
 *
 *  Created on: Feb 24, 2024
 *      Author: salma
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
#include "SYSCFG_config.h"
void SYSCFG_EXTISetPin(u8 Copy_u8LineNo,u8 Copy_u8Pin)
{
	if(Copy_u8LineNo <=3)
	{
		SYSCFG_EXTICR1 &= ~((0b1111) << (Copy_u8LineNo * 4));
		SYSCFG_EXTICR1 |= ((Copy_u8Pin) << (Copy_u8LineNo * 4));
	}
	else if(Copy_u8LineNo <=7)
	{
		SYSCFG_EXTICR2 &= ~((0b1111) << (Copy_u8LineNo * 4));
		SYSCFG_EXTICR2 |= ((Copy_u8Pin) << (Copy_u8LineNo * 4));
	}
	else if(Copy_u8LineNo <=11)
	{
		SYSCFG_EXTICR3 &= ~((0b1111) << (Copy_u8LineNo * 4));
		SYSCFG_EXTICR3 |= ((Copy_u8Pin) << (Copy_u8LineNo * 4));
	}
	else if(Copy_u8LineNo <=15)
	{
		SYSCFG_EXTICR4 &= ~((0b1111) << (Copy_u8LineNo * 4));
		SYSCFG_EXTICR4 |= ((Copy_u8Pin) << (Copy_u8LineNo * 4));
	}

}


