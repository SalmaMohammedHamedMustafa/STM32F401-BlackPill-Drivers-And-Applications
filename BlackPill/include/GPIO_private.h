/*
 * GPIO_private.h
 *
 *  Created on: Feb 23, 2024
 *      Author: salma
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/**********************GPIOA****************************/
#define GPIOA_MODER   *((volatile u32 *)0x40020000)
#define GPIOA_OTYPER  *((volatile u32 *)0x40020004)
#define GPIOA_OSPEEDR *((volatile u32 *)0x40020008)
#define GPIOA_PUPDR   *((volatile u32 *)0x4002000C)
#define GPIOA_IDR     *((volatile u32 *)0x40020010)
#define GPIOA_ODR     *((volatile u32 *)0x40020014)
/********************GPIOB******************************/
#define GPIOB_MODER   *((volatile u32 *)0x40020400)
#define GPIOB_OTYPER  *((volatile u32 *)0x40020404)
#define GPIOB_OSPEEDR *((volatile u32 *)0x40020408)
#define GPIOB_PUPDR   *((volatile u32 *)0x4002040C)
#define GPIOB_IDR     *((volatile u32 *)0x40020410)
#define GPIOB_ODR     *((volatile u32 *)0x40020414)
/*********************GPIOC******************************/
#define GPIOC_MODER   *((volatile u32 *)0x40020800)
#define GPIOC_OTYPER  *((volatile u32 *)0x40020804)
#define GPIOC_OSPEEDR *((volatile u32 *)0x40020808)
#define GPIOC_PUPDR   *((volatile u32 *)0x4002080C)
#define GPIOC_IDR     *((volatile u32 *)0x40020810)
#define GPIOC_ODR     *((volatile u32 *)0x40020814)

#endif /* GPIO_PRIVATE_H_ */
