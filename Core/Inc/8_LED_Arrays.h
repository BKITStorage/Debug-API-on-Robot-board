/*
 * 8_LED_Arrays.h
 *
 *  Created on: May 27, 2025
 *      Author: ASUS
 */

#ifndef INC_8_LED_ARRAYS_H_
#define INC_8_LED_ARRAYS_H_

#include "main.h"

extern SPI_HandleTypeDef * ledsArraySPI;

extern GPIO_TypeDef *Array_LED_LATCH_GPIO_Port;
extern uint16_t Array_LED_LATCH_Pin;
extern GPIO_TypeDef *Array_LED_EN_GPIO_Port;
extern uint16_t Array_LED_EN_Pin;

/**
 * @brief: Truoc khi chay can khoi tao LED bang cach cung cap cac chan xai tuong ung: LATCH, EN, EN1, va EN2
 * */
void led_init (SPI_HandleTypeDef * spi, GPIO_TypeDef *LATCH_GPIO_Port, uint16_t LATCH_Pin,
			   GPIO_TypeDef *EN_GPIO_Port, uint16_t EN_Pin);

/**
 * @brief: Ham bat tat led tuong ung
 * @params: LED: 0 la LED 1 va 1 la LED 2;
 * 			Mode: 0 la tat, va 1 la bat
 * */
void led_mode (uint8_t Mode);

/**
 * @brief: Hien thi so ra man hinh tuong ung
 * @params: val: Truyen vao so tuong ung: ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D, E, F de hien thi ky tu tuong ung
 * */
void write_8_led_arrays (uint8_t val);

/**
 * @brief: Dao nguoc bit
 * @params: b: gia tri truyen vao de dao nguoc bit
 * @retval: b: gia tri sau khi dao nguoc bit
 */
uint8_t reverse_bits(uint8_t b);

void test_8_led_arrays ();

#endif /* INC_8_LED_ARRAYS_H_ */
