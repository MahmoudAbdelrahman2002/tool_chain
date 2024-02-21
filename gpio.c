/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the STM32F446RE GPIO driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/
#include "gpio.h"
#include "common_macros.h"
#include "ERRORS.h"
#include "stdint.h"
static GPIO_REG_t*  GPIO_REG_Array[MAX_NUM_OF_PORT]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOH};

uint8_t GPIO_pinInit(const PIN_CONFIG_t* config)
{
	if(config->port>=MAX_NUM_OF_PORT||config->pin>=MAX_NUM_OF_PORT)
	{
		return NOK;
	}


	/************************* Mode_Configration    *******************************/

	(GPIO_REG_Array[config->port]->MODER)&=~(3<<(2*(config->pin)));
	(GPIO_REG_Array[config->port]->MODER)|=((config->mode)<<(2*(config->pin)));

	if(config->mode==OUTPUT)
	{
		/******************   OUTPUT_Configration **************************************/

		CLEAR_BIT((GPIO_REG_Array[config->port]->OTYPER),config->pin);
		(GPIO_REG_Array[config->port]->OTYPER)|=(config->type<<config->pin);

		/************************* Speed_Configration    *******************************/
		(GPIO_REG_Array[config->port]->OSPEEDR)&=~(3<<(2*(config->pin)));
		(GPIO_REG_Array[config->port]->OSPEEDR)|=((config->speed)<<(2*(config->pin)));
	}
	/************************* PULL_Configration    *******************************/
	(GPIO_REG_Array[config->port]->PUPDR)&=~(3<<(2*(config->pin)));
	(GPIO_REG_Array[config->port]->PUPDR)|=((config->pull)<<(2*(config->pin)));
	/*******************Alternatve Mode Configration       *****************/
	if(config->mode==ALTERNATIVE)
	{
		uint32_t reg_num=(config->pin)/8;
		uint32_t Pin_num=(config->pin)%8;
		(GPIO_REG_Array[config->port]->AFR[reg_num])&=~(15<<(4*(Pin_num)));
		(GPIO_REG_Array[config->port]->AFR[reg_num])|=((config->alternative)<<(4*(Pin_num)));

	}

return OK;
}
uint8_t GPIO_WritePin(PORT_t port,PIN_t pin,PIN_VAL_t val)
{

	if(port>=MAX_NUM_OF_PORT||pin>=MAX_NUM_OF_PORT)
	{
		return NOK;
	}

	if(val==HIGH)
	{
		SET_BIT((GPIO_REG_Array[port]->ODR),pin);
	}
	else if(val==LOW)
	{
		CLEAR_BIT((GPIO_REG_Array[port]->ODR),pin);
	}
	return OK;

}

