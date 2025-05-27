/*
 * 8_LED_Arrays.c
 *
 *  Created on: May 27, 2025
 *      Author: ASUS
 */

/**
 * @brief: Truoc khi chay can khoi tao LED bang cach cung cap cac chan xai tuong ung: LATCH, EN, EN1, va EN2
 * */
#include "8_LED_Arrays.h"

SPI_HandleTypeDef * ledsArraySPI;

GPIO_TypeDef *Array_LED_LATCH_GPIO_Port;
uint16_t Array_LED_LATCH_Pin;
GPIO_TypeDef *Array_LED_EN_GPIO_Port;
uint16_t Array_LED_EN_Pin;

void led_init (SPI_HandleTypeDef * spi, GPIO_TypeDef *LATCH_GPIO_Port, uint16_t LATCH_Pin,
			   GPIO_TypeDef *EN_GPIO_Port, uint16_t EN_Pin) {
	ledsArraySPI = spi;
	Array_LED_LATCH_GPIO_Port = LATCH_GPIO_Port;
	Array_LED_LATCH_Pin = LATCH_Pin;
	Array_LED_EN_GPIO_Port = EN_GPIO_Port;
	Array_LED_EN_Pin = EN_Pin;
}

/**
 * @brief: Ham bat tat led tuong ung
 * @params: Mode: 0 la tat, va 1 la bat
 * */
void led_mode (uint8_t Mode) {
	HAL_GPIO_WritePin(Array_LED_EN_GPIO_Port, Array_LED_EN_Pin, !Mode);
}

/**
 * @brief: Hien thi so ra man hinh tuong ung
 * @params: val: Truyen vao so tuong ung: ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D, E, F de hien thi ky tu tuong ung
 * */
void write_8_led_arrays (uint8_t val) {
	HAL_SPI_Transmit(ledsArraySPI, (uint8_t)(~val & 0xFF), 1, 50);
	HAL_GPIO_WritePin(Array_LED_LATCH_GPIO_Port, Array_LED_LATCH_Pin, 1);
	HAL_Delay(10);
	HAL_GPIO_WritePin(Array_LED_LATCH_GPIO_Port, Array_LED_LATCH_Pin, 0);
}

void test_8_led_arrays () {
	led_mode (1);
	for (uint8_t i = 0; i < 256; i++) {
	  write_8_led_arrays(i);
	  HAL_Delay(500);
	}
}
