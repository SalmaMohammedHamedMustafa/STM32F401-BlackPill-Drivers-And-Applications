/*
 * DMA_program.c
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "definition.h"
#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"


void DMA_voidChannelInit(u8 Copy_u8Channel,u8 Copy_u8Stream)
{
	/*channel selection*/
	/*Copy_u8Channel&=0x07;
	u32 Local_u32Channel = (u32) Copy_u8Channel;
	Local_u32Channel=Local_u32Channel<<25;
	DMA -> DMAStream[Copy_u8Stream].DMA_SCR |= Local_u32Channel;*/
/*
 * 1- memory to memory
 *2- size=32 bit
 *3-MINC&PINK activated
 *4-no circular
 *5-transfer int
 *6- stream disabled */
	CLR_BIT(DMA -> DMAStream[Copy_u8Stream].DMA_SCR,0);
	DMA -> DMAStream[Copy_u8Stream].DMA_SCR = 0x00035690;
}
void DMA_voidChannelStart(u8 Copy_u8Stream,u32 *Copy_pu32SourceAdd,u32 *Copy_pu32DestinationAdd,u16 Copy_u16BlockLength )
{
	//make sure channel is disabled
	CLR_BIT(DMA -> DMAStream[Copy_u8Stream].DMA_SCR,0);
	//Addresses
	DMA -> DMAStream[Copy_u8Stream].DMA_SM0AR=Copy_pu32SourceAdd;
	DMA -> DMAStream[Copy_u8Stream].DMA_SM1AR=Copy_pu32DestinationAdd;
	//block length
	DMA -> DMAStream[Copy_u8Stream].DMA_SNDTR=Copy_u16BlockLength;
	//enable
	SET_BIT(DMA -> DMAStream[Copy_u8Stream].DMA_SCR,0);

}
