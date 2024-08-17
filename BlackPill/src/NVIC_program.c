/*
  * NVIC_program.c
 *
 *  Created on: Feb 12, 2024
 *      Author: salma
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC.private.h"
#include "NVIC.config.h"

void NVIC_voidEnableInterrupt(u8 copy_u8IntNum)
{
	if (copy_u8IntNum<=31)
	{
		NVIC_ISER0 = (1 << copy_u8IntNum);
	}
	else if(copy_u8IntNum<=59)
	{
		copy_u8IntNum -=32;
		NVIC_ISER1 = (1 << copy_u8IntNum);
	}
	else
	{
		//error
	}
}

void NVIC_voidDisableInterrupt(u8 copy_u8IntNum)
{
	if (copy_u8IntNum<=31)
	{
		NVIC_ICER0 = (1 << copy_u8IntNum);
	}
	else if(copy_u8IntNum<=59)
	{
		copy_u8IntNum -=32;
		NVIC_ICER1 = (1 << copy_u8IntNum);
	}
	else
	{
		//error
	}
}

void NVIC_voidSetPendingFlag(u8 copy_u8IntNum)
{
	if (copy_u8IntNum<=31)
	{
		NVIC_ISPR0 = (1 << copy_u8IntNum);
	}
	else if(copy_u8IntNum<=59)
	{
		copy_u8IntNum -=32;
		NVIC_ISPR1 = (1 << copy_u8IntNum);
	}
	else
	{
		//error
	}
}

void NVIC_voidClearPendingFlag(u8 copy_u8IntNum)
{
	if (copy_u8IntNum<=31)
	{
		NVIC_ICPR0 = (1 << copy_u8IntNum);
	}
	else if(copy_u8IntNum<=59)
	{
		copy_u8IntNum -=32;
		NVIC_ICPR1 = (1 << copy_u8IntNum);
	}
	else
	{
		//error
	}
}

u8 NVIC_voidGetActiveFlag(u8 copy_u8IntNum)
{
	u8 local_u8Result=0;
	if (copy_u8IntNum<=31)
	{
		local_u8Result=get_bit(NVIC_IABR0,copy_u8IntNum);
	}
	else if(copy_u8IntNum<=59)
	{
		copy_u8IntNum -=32;
		local_u8Result=get_bit(NVIC_IABR1,copy_u8IntNum);
	}
	else
	{
		//error
	}
	return local_u8Result;
}

void NVIC_voidSetPriority(s8 copy_s8IntID, u8 copy_u8GroupPriorty, u8 copy_u8Subpriority )
{
	/*external peripheral*/
	u8 LocalPriority=copy_u8Subpriority|(copy_u8GroupPriorty<<((NVIC_GruopSubDistribution-0x05FA0300)/256));
	if(copy_s8IntID>=0)
	{
		NVIC_IPR[copy_s8IntID]=LocalPriority<<4;
	}
}

void NVIC_Init()
{
	#define SCB_AIRCR   (*((volatile u32 *)0xE000ED0C))
	SCB_AIRCR=0xFA050000;
	SCB_AIRCR=NVIC_GruopSubDistribution;
}
