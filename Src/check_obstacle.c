#include "check_obstacle.h"

void check_obstacle(){

	while(HAL_GPIO_ReadPin (GPIOD, Sensor_Pin)){
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 128);
		HAL_GPIO_WritePin(GPIOE, IN1_IN3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE, IN2_IN4_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOE,IN1_IN3_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE,IN2_IN4_2_Pin, GPIO_PIN_SET);
	}

}

void write_lcd(uint16_t output){

	char data[10];
	sprintf(data, "%d", output);
	lcd_puts(0,0,(int8_t*)"Speed=");
	lcd_puts(0,7,(int8_t*)data);
	lcd_puts(0,12,(int8_t*)"T/s");
	lcd_clear();

}

