#include "ultra.h"


void UsDelay(int time) {
	if (time < 2)
		time = 2;
	usTIM->ARR = time - 1;
	usTIM->EGR = 1;
	usTIM->SR &= ~1;
	usTIM->CR1 |= 1;
	while ((usTIM->SR & 0x0001) != 1);
	usTIM->SR &= ~(0x0001);

}

int Distance(){

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
	UsDelay(3);

	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
	UsDelay(10);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);

	while (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1) == GPIO_PIN_RESET);
	Mystruct.numticks = 0;

	while (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_1) == GPIO_PIN_SET) {
		Mystruct.numticks++;
		UsDelay(2);
	}

	Mystruct.distance = (int)(Mystruct.numticks * 2.8 * speedofs);

	return Mystruct.distance;

}
