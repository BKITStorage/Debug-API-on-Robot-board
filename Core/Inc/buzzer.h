/*
 * buzzer.h
 *
 *  Created on: May 27, 2025
 *      Author: truon
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "main.h"

extern TIM_HandleTypeDef htim2;




void buzzer_on();
void buzzer_off();
void test_buzzer();

typedef struct {
    uint16_t freq;
    uint16_t duration;
} Note;

void buzzer_init(TIM_HandleTypeDef *htim, uint32_t channel);
void buzzer_play_note(uint16_t freq, uint16_t duration_ms);
void buzzer_play_song(const Note* song, uint16_t length);

#endif /* INC_BUZZER_H_ */
