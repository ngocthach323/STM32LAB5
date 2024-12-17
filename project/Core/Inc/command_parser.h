/*
 * command_parser.h
 *
 *  Created on: Dec 11, 2024
 *      Author: ACER
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "main.h"

#define MAX_BUFFER_SIZE		30

extern uint8_t temp;
extern uint8_t buffer[];
extern uint8_t buffer_index;
extern uint8_t buffer_flag;
extern uint8_t command_flag;
extern char command_data[];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void command_parser_fsm();

#endif /* INC_COMMAND_PARSER_H_ */
