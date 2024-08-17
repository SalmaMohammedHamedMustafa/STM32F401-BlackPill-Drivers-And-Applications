/*
 * OS_privete.h
 *
 *  Created on: Mar 1, 2024
 *      Author: salma
 */

#ifndef OS_PRIVETE_H_
#define OS_PRIVETE_H_

typedef struct
{
	u16 period;
	u8 FirstDelay;
	u8 State;
	void (*Fptr) (void);
}Task;

enum States{

	ready ,
	running
};

static Task OSTasks[NumberOfTasks];
#endif /* OS_PRIVETE_H_ */
