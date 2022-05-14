/*
 * PID.h
 *
 *  Created on: May 12, 2022
 *      Author: Ju_Eun
 */

#ifndef INC_PID_H_
#define INC_PID_H_

#include "stm32f4xx_hal.h"
#include "math.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim1;

#define IN2_IN4_Pin GPIO_PIN_2
#define IN1_IN3_Pin GPIO_PIN_1
#define IN2_IN4_2_Pin GPIO_PIN_4
#define IN1_IN3_2_Pin GPIO_PIN_3


struct{
	uint8_t count;
	uint8_t prevcount;
	int16_t output;
	int16_t error;
	int8_t queuespeed;
	float derivative;
	float last_error;
	float integral;
}PID;

int8_t PIDe(float kp,float ki,float kd,uint8_t wantedvalue);




#endif /* INC_PID_H_ */
