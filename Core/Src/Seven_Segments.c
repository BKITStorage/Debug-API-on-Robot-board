/*
 * Seven_Segments.c
 *
 *  Created on: May 27, 2025
 *      Author: ASUS
 */

#include "Seven_Segments.h"

enum Map_Seven_Segment val[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D, E, F};

SPI_HandleTypeDef * sevenSegmentsSPI;

GPIO_TypeDef *LED_LATCH_GPIO_Po;
uint16_t LED_LATCH_P;
GPIO_TypeDef *LED_EN_GPIO_Po;
uint16_t LED_EN_P;
GPIO_TypeDef *LED_EN1_GPIO_Po;
uint16_t LED_EN1_P;
GPIO_TypeDef *LED_EN2_GPIO_Po;
uint16_t LED_EN2_P;


/**
 * @brief: Truoc khi chay can khoi tao LED bang cach cung cap cac chan xai tuong ung: LATCH, EN, EN1, va EN2
 * */
void seven_segments_led_init (SPI_HandleTypeDef * spi,
				GPIO_TypeDef *LATCH_GPIO_Port, uint16_t LATCH_Pin,
			   GPIO_TypeDef *EN_GPIO_Port, uint16_t EN_Pin,
			   GPIO_TypeDef *EN1_GPIO_Port, uint16_t EN1_Pin,
			   GPIO_TypeDef *EN2_GPIO_Port, uint16_t EN2_Pin) {
	sevenSegmentsSPI = spi;
	LED_LATCH_GPIO_Po = LATCH_GPIO_Port;
	LED_LATCH_P = LATCH_Pin;
	LED_EN_GPIO_Po = EN_GPIO_Port;
	LED_EN_P = EN_Pin;
	LED_EN1_GPIO_Po = EN1_GPIO_Port;
	LED_EN1_P = EN1_Pin;
	LED_EN2_GPIO_Po = EN2_GPIO_Port;
	LED_EN2_P = EN2_Pin;
}

/**
 * @brief: Ham bat tat led tuong ung
 * @params: LED: 0 la LED 1 va 1 la LED 2;
 * 			Mode: 0 la tat, va 1 la bat
 * */
void seven_segments_led_mode (uint8_t LED, uint8_t Mode) {
	GPIO_TypeDef * Port;
	uint16_t Pin;
	if (LED == 0) {
		Port = LED_EN1_GPIO_Po;
		Pin = LED_EN1_P;
	} else if (LED == 1) {
		Port = LED_EN2_GPIO_Po;
		Pin = LED_EN2_P;
	}
	HAL_GPIO_WritePin(LED_EN_GPIO_Port, LED_EN_Pin, 0);
	HAL_GPIO_WritePin(Port, Pin, !Mode);
}

/**
 * @brief: Hien thi so ra man hinh tuong ung
 * @params: val: Truyen vao so tuong ung: ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D, E, F de hien thi ky tu tuong ung
 * */
void write_seven_segments_led (uint8_t val) {
	HAL_SPI_Transmit(sevenSegmentsSPI, (&val), 1, 50);
	HAL_GPIO_WritePin(LED_LATCH_GPIO_Po, LED_LATCH_P, 1);
	HAL_Delay(10);
	HAL_GPIO_WritePin(LED_LATCH_GPIO_Po, LED_LATCH_P, 0);
}

void test_seven_segments_led_debug () {
	for (int i = 0; i < 16; i++) {
	  write_seven_segments_led (val[i]);
	  HAL_Delay(4000);
	}
}
