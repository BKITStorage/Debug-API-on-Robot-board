/*
 * buzzer.c
 *
 *  Created on: May 27, 2025
 *      Author: truon
 */

#include "buzzer.h"

void buzzer_on(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}
void buzzer_off(){
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
}
void test_buzzer(){
	buzzer_on();
	HAL_Delay(50);
	buzzer_off();
	HAL_Delay(100);
}
static TIM_HandleTypeDef *buzzer_htim = NULL;
static uint32_t buzzer_channel = 0;

void buzzer_init(TIM_HandleTypeDef *htim, uint32_t channel)
{
    buzzer_htim = htim;
    buzzer_channel = channel;
    HAL_TIM_PWM_Start(buzzer_htim, buzzer_channel);
}

void buzzer_play_note(uint16_t freq, uint16_t duration_ms)
{
    if (freq == 0) {
        HAL_TIM_PWM_Stop(buzzer_htim, buzzer_channel);
        HAL_Delay(duration_ms);
        HAL_TIM_PWM_Start(buzzer_htim, buzzer_channel);
        return;
    }

    uint32_t timer_clk = 72000000; // Giả sử clock timer 72MHz
    uint32_t period = 1000;
    uint32_t prescaler = (timer_clk / (freq * period)) - 1;

    buzzer_htim->Instance->PSC = prescaler;
    buzzer_htim->Instance->ARR = period - 1;
    buzzer_htim->Instance->CCR1 = period / 2;

    HAL_TIM_PWM_Start(buzzer_htim, buzzer_channel);
    HAL_Delay(duration_ms);
    HAL_TIM_PWM_Stop(buzzer_htim, buzzer_channel);
}

void buzzer_play_song(const Note* song, uint16_t length)
{
    for (uint16_t i = 0; i < length; ++i)
    {
        buzzer_play_note(song[i].freq, song[i].duration);
        HAL_Delay(20);
    }
}

