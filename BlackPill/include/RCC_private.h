/**
 *Reset and Clock Control (RCC) peripheral.
 *
 * @author Salma Mohammed Hamed
 * @date 1 Feb 2024
 * @version V01
 *
*/
#ifndef __RCC_PRIVATE_H__
#define __RCC_PRIVATE_H__
#include "STD_TYPES.h"
/*registers definition*/
/*choose processor clk*/
#define RCC_CR     			*((volatile u32 *)0x40023800)
#define RCC_PLLCFGR     	*((volatile u32 *)0x40023804)
#define RCC_CFGR     		*((volatile u32 *)0x40023808)
/***************************/
#define RCC_CIR				*((volatile u32 *)0x4002380c)
#define RCC_AHB1RSTR	    *((volatile u32 *)0x40023810)
#define RCC_AHB2RSTR		*((volatile u32 *)0x40023814)
#define RCC_APB1RSTR		*((volatile u32 *)0x40023820)
#define RCC_APB2RSTR		*((volatile u32 *)0x40023824)
/*priphrals clk*/
#define RCC_AHB1ENR			*((volatile u32 *)0x40023830) //for clock, enable and disable the clock on the different peripherals
#define RCC_AHB2ENR			*((volatile u32 *)0x40023834)
#define RCC_APB1ENR			*((volatile u32 *)0x40023840) //for clock, enable and disable the clock on the different peripherals
#define RCC_APB2ENR			*((volatile u32 *)0x40023844) //for clock, enable and disable the clock on the different peripherals
/********************************/
#define RCC_BDCR			*((volatile u32 *)0x40023870)
#define RCC_CSR				*((volatile u32 *)0x40023874)
/*****************Clk types*****************/
#define 	RCC_HSE_CRYSTAL 0
#define	    RCC_HSE_RC      1
#define 	RCC_HSI         2
#define 	RCC_PLL         3

/*****************PLL options***************/
#define RCC_PLL_IN_HSI_DIV_2    0
#define	RCC_PLL_IN_HSE_DIV_2    1 
#define RCC_PLL_IN_HSE          2

/*Important bits*/
#define RCC_HSIRDY_BIT			1
#define RCC_HSERDY_BIT			17
#define RCC_PLLRDY_BIT			25


#endif /**< __RCC_PRIVATE_H__ */
