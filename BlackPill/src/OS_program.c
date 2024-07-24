/*
 * OS_program.c
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "SysTick_interface.h"
#include "OS_interface.h"
#include "OS_config.h"
#include "OS_privete.h"



void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Period,u8 Copy_u8FirstDelay,void (*TFptr)(void))
{
	OSTasks[Copy_u8ID].period=Copy_u16Period;
	OSTasks[Copy_u8ID].Fptr=TFptr;
	OSTasks[Copy_u8ID].FirstDelay=Copy_u8FirstDelay;
}
void Scheduler()
{
	u8 i=0;
	static u32 TickCounts=0;
	for (i=0;i<NumberOfTasks;i++)
	{
		if ( OSTasks[i].Fptr!=NULL && TickCounts>=(OSTasks[i].FirstDelay*OSTasks[i].period) && (TickCounts % OSTasks[i].period) == 0 )
		{
			OSTasks[i].Fptr();
		}
	}
	TickCounts++;
}

void OS_voidStart()
{
	STK_Init();
	STK_SetIntervalPeriodic(TickTime,Scheduler);
}



