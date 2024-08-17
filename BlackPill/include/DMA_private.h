/*
 * DMA_private.h
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct
{
	volatile u32 DMA_SCR;
	volatile u32 DMA_SNDTR;
	volatile u32 DMA_SPAR;
	volatile u32 DMA_SM0AR;
	volatile u32 DMA_SM1AR;
	volatile u32 DMA_SFCR;
}Stream;
typedef struct
{
	volatile u32 DMA_LISR;
	volatile u32 DMA_HISR;
	volatile u32 DMA_LIFCR;
	volatile u32 DMA_HIFCR;
	Stream DMAStream [8];
}DMA_t;

#define DMA ((volatile DMA_t *) 0x40026000 )

#endif /* DMA_PRIVATE_H_ */
