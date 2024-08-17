/*
 * UART_private.h
 *
 *  Created on: Mar 9, 2024
 *      Author: salma
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

typedef struct
{
  volatile u32 SR;
  volatile u32 DR;
  volatile u32 BRR;
  volatile u32 CR1;
  volatile u32 CR2;
  volatile u32 CR3;
  volatile u32 GTPR;
} USART_t;

#define UART ((volatile USART_t *) 0x40011000 )

#endif /* UART_PRIVATE_H_ */
