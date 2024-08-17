/*
 * Bit_Math.h
 *
 *  Created on: Sep 9, 2023
 *      Author: salma
 */

#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

#define SET_BIT(REG, BIT_NUMBER) 	REG |= (1<< BIT_NUMBER)
#define CLR_BIT(REG, BIT_NUMBER) 	REG &= ~(1<< BIT_NUMBER)
#define TOG_BIT(REG, BIT_NUMBER) 	REG ^= (1<< BIT_NUMBER)
#define GET_BIT(REG, BIT_NUMBER) 	((REG & (1<< BIT_NUMBER)) >> BIT_NUMBER)

#define set_bit(reg,bit)  reg|=(1<<bit)
#define clear_bit(reg,bit)  reg&=~(1<<bit)
#define toggle_bit(reg,bit)  reg^=(1<<bit)
#define get_bit(reg,bit)  ((reg>>bit)&1)


#endif /**< __BIT_MATH_H__ */

