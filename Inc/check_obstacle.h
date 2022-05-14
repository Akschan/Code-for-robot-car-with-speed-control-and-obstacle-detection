#ifndef INC_CHECK_OBSTACLE_H_
#define INC_CHECK_OBSTACLE_H_

#include "stm32f4xx_hal.h"
#include "lcd_txt.h"
#include "stdio.h"

extern TIM_HandleTypeDef htim1;

#define IN2_IN4_Pin GPIO_PIN_2
#define IN1_IN3_Pin GPIO_PIN_1
#define IN2_IN4_2_Pin GPIO_PIN_4
#define IN1_IN3_2_Pin GPIO_PIN_3
#define Sensor_Pin GPIO_PIN_2

void check_obstacle();
void write_lcd(uint16_t output);



#endif
