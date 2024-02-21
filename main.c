/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "RCC.h"
#include "gpio.h"
const char x=10;


int main(void)
{

int l_variable1=10;

	RCC_AHB1EnablePeriphral(GPIOA_ENABLE);
	PIN_CONFIG_t config={
		.port=PORTA,
		.pin=PIN5,
		.mode=OUTPUT,
		.speed=LOW_SPEED,
		.type=PUSH_PULL,
		.pull=NO_PULL

	};
   GPIO_pinInit(&config);
   GPIO_WritePin(PORTA, PIN5,HIGH);
   int l_variable2=110;
	for(;;);
}