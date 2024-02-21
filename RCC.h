
#ifndef RCC_H_
#define RCC_H_


#include "STM32F446XX.h"
#include "stdint.h"
#include "std_types.h"
/***********************  RCC REGISTER DEFINITION **************************************/
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLL_CFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1_RSTR;
	volatile uint32_t AHB2_RSTR;
	volatile uint32_t AHB3_RSTR;

	volatile uint32_t reversed_1;

	volatile uint32_t APB1_RSTR;
	volatile uint32_t APB2_RSTR;

	volatile uint32_t reversed_2;
	volatile uint32_t reversed_3;

	volatile uint32_t AHB1_ENR;
	volatile uint32_t AHB2_ENR;
	volatile uint32_t AHB3_ENR;

	volatile uint32_t reversed_4;

	volatile uint32_t APB1_ENR;
	volatile uint32_t APB2_ENR;

	volatile uint32_t reversed_5;
	volatile uint32_t reversed_6;

	volatile uint32_t AHB1_LPENR;
	volatile uint32_t AHB2_LPENR;
	volatile uint32_t AHB3_LPENR;

	volatile uint32_t reversed_7;

	volatile uint32_t APB1_LPENR;
	volatile uint32_t APB2_LPENR;

	volatile uint32_t reversed_8;
	volatile uint32_t reversed_9;

	volatile uint32_t BDCR;
	volatile uint32_t CSR;

	volatile uint32_t reversed_10;
	volatile uint32_t reversed_11;

	volatile uint32_t SS_CGR;
	volatile uint32_t PLLI2_SCFGR;
	volatile uint32_t PLL_SAI_CFGR;
	volatile uint32_t PLL_DCK_CFGR;
	volatile uint32_t CK_GATENR;
	volatile uint32_t DCK_CFGR2;

}RCC_REG;

/** enum for STATE of clk on or off            **/


typedef enum
{
	ON,
	OFF
}RCC_CLK_STATE;



/**********************type of clk  *******************************/
typedef enum
{
	HSI=0,
	HSE,
	PLL_P,
	PLL_R

}RCC_CLK_TYPE;

/******************   structure to configre clk setting               *********************************/
typedef struct
{

	RCC_CLK_TYPE clk;
	RCC_CLK_STATE state;

}RCC_CLK_SETTING_CONFIG;


/**************        HSE_configration         ************/
typedef enum
{
	HSE_DIV_BY_1,
	HSE_DIV_BY_2

}RCC_HSE_CONFIG;

/***********************   PLL configration       ************************/
typedef enum
{
	PLL_DIV_BY_2=2,PLL_DIV_BY_3,PLL_DIV_BY_4,PLL_DIV_BY_5,PLL_DIV_BY_6,
	PLL_DIV_BY_7,PLL_DIV_BY_8


}PLL_DIVIDOR;
typedef enum
{
	PLL_MUL_BY_50=50,PLL_MUL_BY_51,PLL_MUL_BY_52,PLL_MUL_BY_53,
	PLL_MUL_BY_54,PLL_MUL_BY_55,PLL_MUL_BY_56,PLL_MUL_BY_57,
	PLL_MUL_BY_58,PLL_MUL_BY_59,PLL_MUL_BY_60,

}PLL_MULTIPLIER;
typedef enum
{
	MAIN_DIV_BY_2=0,MAIN_DIV_BY_4,MAIN_DIV_BY_6,MAIN_DIV_BY_8,

}PLL_MAIN_DIVIDOR;
typedef enum
{
	PLL_HSI,PLL_HSE

}PLL_SOURCE;


typedef struct
{

	PLL_DIVIDOR div;
	PLL_MULTIPLIER mul;
	PLL_MAIN_DIVIDOR main_dividor;
	PLL_SOURCE src;
}RCC_PLL_CONFiGRATION;


typedef enum
{
	GPIOA_ENABLE=0,GPIOB_ENABLE,GPIOC_ENABLE,GPIOD_ENABLE,
	GPIOE_ENABLE,GPIOF_ENABLE,GPIOG_ENABLE,GPIOH_ENABLE,
	CRC_ENABLE=12,BKB_SRAM_ENABLE=18,DMA1_ENABLE=21,
	DMA2_ENABLE=22,OTGHS_ENABLE=29,OTGHS_ULPIEN_ENABLE=30

}AHB1_PERIPHRAL;




#define   RCC    ((RCC_REG*)RCC_BASE_ADDRESS)
/******************  function prototype  *********************/



void RCC_setClkState(  const RCC_CLK_SETTING_CONFIG* config);
uint8_t RCC_setSystemClk(RCC_CLK_TYPE clk);
void RCC_PLLconfig(const RCC_PLL_CONFiGRATION* config);
void RCC_AHB1EnablePeriphral(AHB1_PERIPHRAL periphral);
void RCC_AHB1DisablePeriphral(AHB1_PERIPHRAL periphral);

#endif /* RCC_H_ */
