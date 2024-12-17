/*
 * software_timer.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ACER
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define TICK 10

extern int timer_flag[10];
int timer_counter[10];

void setTimer(int index, int counter);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
