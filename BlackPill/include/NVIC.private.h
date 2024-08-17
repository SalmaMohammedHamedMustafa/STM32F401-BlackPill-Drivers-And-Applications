/*
 * NVIC.private.h
 *
 *  Created on: Feb 12, 2024
 *      Author: salma
 */

#ifndef INC_NVIC_PRIVATE_H_
#define INC_NVIC_PRIVATE_H_

#define NVIC_ISER0     (*((volatile u32 *)0xE000E100)) /** INTERRUPT SET-ENABLE REGISTERS 0 to 31 */
#define NVIC_ISER1     (*((volatile u32 *)0xE000E104)) /** INTERRUPT SET-ENABLE REGISTERS 32 to 63 */

#define NVIC_ICER0     (*((volatile u32 *)0xE000E180)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 0 to 31 */
#define NVIC_ICER1     (*((volatile u32 *)0xE000E184)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 32 to 63 */


#define NVIC_ISPR0     (*((volatile u32 *)0xE000E200)) /**< INTERRUPT SET-PENDING REGISTERS 0 to 31 */
#define NVIC_ISPR1     (*((volatile u32 *)0xE000E204)) /**< INTERRUPT SET-PENDING REGISTERS 32 to 63 */


#define NVIC_ICPR0     (*((volatile u32 *)0xE000E280)) /**< INTERRUPT CLEAR-PENDING REGISTERS 0 to 31 */
#define NVIC_ICPR1     (*((volatile u32 *)0xE000E284)) /**< INTERRUPT CLEAR-PENDING REGISTERS 32 to 63 */


#define NVIC_IABR0     (*((volatile u32 *)0xE000E300))  /*Read Active flag 0 to 31*/
#define NVIC_IABR1     (*((volatile u32 *)0xE000E304))  /*Read Active flag 32 to 63*/

#define NVIC_IPR    (((volatile u8 *)0xE000E400)) /**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */

#endif /* INC_NVIC_PRIVATE_H_ */
