/*
 * uart_communication.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ACER
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include "main.h"

#define INIT_COMMNUNICATION		5
#define RTS_COMMNUNICATION		6
#define OK_COMMNUNICATION		7

extern uint32_t ADC_value;
extern int communication_status;

void uart_communication_fsm();

#endif /* INC_UART_COMMUNICATION_H_ */
