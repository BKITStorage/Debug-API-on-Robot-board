/*
 * button.h
 *
 *  Created on: May 30, 2025
 *      Author: Divu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include <stdint.h>

#define ROWS 5
#define COLS 8

typedef struct
{
    int rows;
    int cols;
    int data[ROWS][COLS]; //
    int des;
} button;


button *create_button();
void printButtonCache(button *btn);
void fillButtonCache(uint8_t input, button *btn);
uint8_t getButtonValue(button *btn);
void freeButtonCache(button *btn);



#endif /* INC_BUTTON_H_ */
