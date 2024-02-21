#include "RCC.h"
#include "common_macros.h"
void RCC_setClkState(  const RCC_CLK_SETTING_CONFIG* config)
{
	if(config->clk==HSI)
	{
		if(config->state==ON)
		{
			SET_BIT(RCC->CR,0);
			while(BIT_IS_CLEAR(RCC->CR,1));
		}
		else
		{
			CLEAR_BIT(RCC->CR,0);
		}
	}
	else if(config->clk==HSE)
	{
		if(config->state==ON)
		{
			SET_BIT(RCC->CR,16);
			while(BIT_IS_CLEAR(RCC->CR,17));
		}
		else
		{
			CLEAR_BIT(RCC->CR,16);
		}

	}
	else if(config->clk==PLL_P)
	{
		if(config->state==ON)
		{
			SET_BIT(RCC->CR,24);
			while(BIT_IS_CLEAR(RCC->CR,25));
		}
		else
		{
			CLEAR_BIT(RCC->CR,24);
		}
	}

}
uint8_t RCC_setSystemClk(RCC_CLK_TYPE clk)
{
	if(clk==HSE&&GET_BIT(RCC->CR,16))
	{
		RCC->CFGR=(RCC->CFGR&0xFFFFFFFC)|clk;
		return  TRUE;
	}
	else if(clk==HSI&&GET_BIT(RCC->CR,0))
	{
		RCC->CFGR=(RCC->CFGR&0xFFFFFFFC)|clk;
		return  TRUE;
	}
	else if(clk==PLL_P&&GET_BIT(RCC->CR,24))
	{
		RCC->CFGR=(RCC->CFGR&0xFFFFFFFC)|clk;
		return  TRUE;
	}
	else if(clk==PLL_R&&GET_BIT(RCC->CR,24))
	{
		RCC->CFGR=(RCC->CFGR&0xFFFFFFFC)|clk;
		return  TRUE;
	}
	return FALSE;
}
void RCC_PLLconfig(const RCC_PLL_CONFiGRATION* config)
{

	RCC->PLL_CFGR=(RCC->PLL_CFGR&0xFFFCFFFF)|((config->main_dividor)<<16);
	RCC->PLL_CFGR=(RCC->PLL_CFGR&0xFFFFFFC0)|(config->div);
	RCC->PLL_CFGR=(RCC->PLL_CFGR&0xFFFF803F)|((config->mul)<<6);
	if(config->src==PLL_HSI)
	{
		CLEAR_BIT(RCC->PLL_CFGR,22);
	}
	if(config->src==PLL_HSE)
	{
		SET_BIT(RCC->PLL_CFGR,22);
	}


}
void RCC_AHB1EnablePeriphral(AHB1_PERIPHRAL periphral)
{
	SET_BIT(RCC->AHB1_ENR,periphral);
}
void RCC_AHB1DisablePeriphral(AHB1_PERIPHRAL periphral)
{
	CLEAR_BIT(RCC->AHB1_ENR,periphral);

}
