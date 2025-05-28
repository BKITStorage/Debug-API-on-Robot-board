/*
 * LED_debug.c
 *
 *  Created on: May 27, 2025
 *      Author: ADMIN
 */

#include "LED_debug.h"

void test_LED_debug(void){
	HAL_GPIO_TogglePin(LED_debug_GPIO_Port, LED_debug_Pin);
	HAL_Delay(100);
}
