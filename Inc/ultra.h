#ifndef INC_ULTRA_H_
#define INC_ULTRA_H_

#include "stm32f4xx_hal.h"
#define usTIM TIM4

struct {
	int numticks;
	int distance;
}Mystruct;

#define speedofs 0.0343f

void UsDelay(int time);
int Distance();



#endif
