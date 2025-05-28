/*
 * Seven_Segments.h
 *
 *  Created on: May 27, 2025
 *      Author: ASUS
 */

#ifndef INC_SEVEN_SEGMENTS_H_
#define INC_SEVEN_SEGMENTS_H_

#include "main.h"

enum Map_Seven_Segment {ZERO = 0x03, ONE=0x9F, TWO=0x25, THREE=0x0D, FOUR=0x99, FIVE=0x49, SIX=0x41, SEVEN=0x1F, EIGHT=0x01, NINE=0x09, A=0xC5, B=0xC1, C=0xE5, D=0x85, E=0x61, F=0x71};
extern enum Map_Seven_Segment val[];

extern SPI_HandleTypeDef * sevenSegmentsSPI;

extern GPIO_TypeDef *LED_LATCH_GPIO_Po;
extern uint16_t LED_LATCH_P;
extern GPIO_TypeDef *LED_EN_GPIO_Po;
extern uint16_t LED_EN_P;
extern GPIO_TypeDef *LED_EN1_GPIO_Po;
extern uint16_t LED_EN1_P;
extern GPIO_TypeDef *LED_EN2_GPIO_Po;
extern uint16_t LED_EN2_P;

/**
 * @brief: Truoc khi chay can khoi tao LED bang cach cung cap cac chan xai tuong ung: LATCH, EN, EN1, va EN2
 * */
void seven_segments_led_init (SPI_HandleTypeDef * spi,
							  GPIO_TypeDef *LATCH_GPIO_Port, uint16_t LATCH_Pin,
							  GPIO_TypeDef *EN_GPIO_Port, uint16_t EN_Pin,
							  GPIO_TypeDef *EN1_GPIO_Port, uint16_t EN1_Pin,
							  GPIO_TypeDef *EN2_GPIO_Port, uint16_t EN2_Pin);

/**
 * @brief: Ham bat tat led tuong ung
 * @params: LED: 0 la LED 1 va 1 la LED 2;
 * 			Mode: 0 la tat, va 1 la bat
 * */
void seven_segments_led_mode (uint8_t LED, uint8_t Mode);

/**
 * @brief: Hien thi so ra man hinh tuong ung
 * @params: val: Truyen vao so tuong ung: ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, D, E, F de hien thi ky tu tuong ung
 * */
void write_seven_segments_led (uint8_t val);

void test_seven_segments_led_debug ();
void display_num (uint8_t value) ;
#endif /* INC_SEVEN_SEGMENTS_H_ */
