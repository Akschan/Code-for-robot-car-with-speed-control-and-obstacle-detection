#include "PID.h"

int8_t PIDe(float kp,float ki,float kd,uint8_t wantedvalue){

	PID.prevcount = __HAL_TIM_GET_COUNTER(&htim3);
	HAL_Delay(10);
	PID.count = __HAL_TIM_GET_COUNTER(&htim3);

	PID.queuespeed = (PID.count - PID.prevcount);

	PID.error = wantedvalue - PID.queuespeed;

	PID.integral = PID.integral + PID.error;
	PID.derivative = PID.error - PID.last_error;

	PID.output = (kp*PID.error)+(ki*PID.integral)+(kd*PID.derivative);
	PID.output = floor(PID.output);

	if(PID.output > 255){
		PID.output = 255;
	}
	else if (PID.output<-255){
		PID.output = -255;
	}
	if(PID.output>0){
		HAL_GPIO_WritePin(GPIOE, IN1_IN3_Pin|IN1_IN3_2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE, IN2_IN4_Pin|IN2_IN4_2_Pin, GPIO_PIN_RESET);
	}
	else if(PID.output<0){
		PID.output = 0;
		HAL_GPIO_WritePin(GPIOE, IN1_IN3_Pin|IN1_IN3_2_Pin, GPIO_PIN_RESET); //to test later when card availale
		HAL_GPIO_WritePin(GPIOE, IN2_IN4_Pin|IN2_IN4_2_Pin, GPIO_PIN_SET);
	}

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, PID.output);

	return PID.queuespeed;
}
