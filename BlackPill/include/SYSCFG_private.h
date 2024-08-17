/*
 * SYSCFG_private.h
 *
 *  Created on: Feb 24, 2024
 *      Author: salma
 */

#ifndef SYSCFG_PRIVATE_H_
#define SYSCFG_PRIVATE_H_

#define SYSCFG_BaseAdd    0x40013800

#define SYSCFG_EXTICR1   *((volatile u32 *)0x40013808)
#define SYSCFG_EXTICR2   *((volatile u32 *)(SYSCFG_BaseAdd+0x0C))
#define SYSCFG_EXTICR3   *((volatile u32 *)(SYSCFG_BaseAdd+0x10))
#define SYSCFG_EXTICR4   *((volatile u32 *)(SYSCFG_BaseAdd+0x14))


#endif /* SYSCFG_PRIVATE_H_ */
