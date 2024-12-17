/*
 * uart_communication.c
 *
 *  Created on: Dec 11, 2024
 *      Author: ACER
 */
#include "software_timer.h"
#include "uart_communication.h"
#include "command_parser.h"

uint32_t ADC_value = 0;
char str[30];
char end_str[30] = "END\r\n";
int communication_status = 0;

void uart_communication_fsm() {
	switch(communication_status) {
		case 0:
			if (command_flag == 1) {
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 100);
				communication_status = 1;
				setTimer(0, 3000);
				break;
			}
		case 1:
			if (command_flag == 2) {
				 HAL_UART_Transmit(&huart2, (void *)end_str, sizeof(end_str), 100);
				 command_flag = 0;
				 communication_status = 0;
			}
			else {
				if (timer_flag[0] == 1) {
					setTimer(0, 3000);
					HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 100);
				}
			}
			break;
	}
}

