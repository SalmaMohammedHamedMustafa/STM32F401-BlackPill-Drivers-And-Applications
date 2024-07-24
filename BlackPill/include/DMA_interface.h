/*
 * DMA_interface.h
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA_voidChannelInit(u8 Copy_u8Channel,u8 Copy_u8Stream);
void DMA_voidChannelStart(u8 Copy_u8Stream,u32 *Copy_pu32SourceAdd,u32 *Copy_pu32DestinationAdd,u16 Copy_u16BlockLength );


#endif /* DMA_INTERFACE_H_ */
