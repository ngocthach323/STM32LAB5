/*
 * command_parser.c
 *
 *  Created on: Dec 11, 2024
 *      Author: ACER
 */
#include "command_parser.h"
#include "uart_communication.h"

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buffer_index = 0;
uint8_t buffer_flag = 0;
uint8_t command_flag = 0;
uint8_t command_index = 0;
int command_status = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) {
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		buffer[buffer_index++] = temp;
		if (buffer_index == 30) {
			buffer_index = 0;
		}
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

void command_parser_fsm() {
	for (uint8_t i = 0; i < buffer_index; i++) {
		switch (command_status) {
			case 0:
				if (buffer[i] == '!') {
					command_status = 1;
				}
				break;
			case 1:
				if (buffer[i] == 'R') {
					command_status = 2;
				}
				else if (buffer[i] == 'O') {
					command_status = 5;
				}
				else {
					command_status = 0;
				}
				break;
			case 2:
				if (buffer[i] == 'T') {
					command_status = 3;
				}
				else {
					command_status = 0;
				}
				break;
			case 3:
				if (buffer[i] == 'S') {
					command_status = 4;
				}
				else {
					command_status = 0;
				}
				break;
			case 4:
				if (buffer[i] == '#') {
					command_flag = 1;
				}
				else {
					command_status = 0;
				}
				break;
			case 5:
				if (buffer[i] == 'K') {
					command_status = 6;
				}
				else {
					command_status = 0;
				}
				break;
			case 6:
				if (buffer[i] == '#') {
					command_flag = 2;
				}
				else {
					command_status = 0;
				}
				break;
		}
	}
}



