
#ifndef GPIO_H_
#define GPIO_H_
#include "STM32F446XX.h"
#include "stdint.h"
/*********************  GPIO_REGISTERS     **********************/
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];


}GPIO_REG_t;

/**************************************************************************/
#define GPIOA ((GPIO_REG_t*)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_REG_t*)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_REG_t*)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_REG_t*)GPIOD_BASE_ADDRESS)
#define GPIOE ((GPIO_REG_t*)GPIOE_BASE_ADDRESS)
#define GPIOF ((GPIO_REG_t*)GPIOF_BASE_ADDRESS)
#define GPIOG ((GPIO_REG_t*)GPIOG_BASE_ADDRESS)
#define GPIOH ((GPIO_REG_t*)GPIOH_BASE_ADDRESS)
/**************************************************************************/
#define MAX_NUM_OF_PORT 8
#define MAX_NUM_OF_PINS 16
/*********************  enums for GPIO     ************************/



/******************** enum for port    *************************/
typedef enum
{
	LOW=0,
	HIGH
}PIN_VAL_t;

typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH,

}PORT_t;
/******************** enum for pin    *************************/
typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
}PIN_t;
/********************    enum for mode    ********************************/
typedef enum
{
	INPUT=0,
	OUTPUT,
	ALTERNATIVE,
	ANALOG,

}MODE_t;
/******************** enum for output speed    *************************/
typedef enum
{
	LOW_SPEED=0,
	MEDIAM_SPEED,
	FAST_SPEED,
	HIGH_SPEED

}OUTPUT_SPEED_t;
/******************** enum for pull  type   *************************/
typedef enum
{
	NO_PULL,
	PULL_UP,
	PULL_DOWN,

}pull_t;
typedef enum
{
	PUSH_PULL=0,
	OPEN_DRAIN

}OUTPUT_TYPE_t;
typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,

}ALTERNATIVE_FUNCTION_t;
/********************* structure for pin configration       ***********************/
typedef struct
{
	PORT_t port;
	PIN_t pin;
	MODE_t mode;
	OUTPUT_SPEED_t speed;
	OUTPUT_TYPE_t type;
	ALTERNATIVE_FUNCTION_t alternative;
	pull_t pull;
}PIN_CONFIG_t;
/********************  function prototype      *******************/
uint8_t GPIO_pinInit(const PIN_CONFIG_t* config);
uint8_t GPIO_WritePin(PORT_t port,PIN_t pin,PIN_VAL_t val);
uint8_t GPIO_ReadPin(PORT_t port,PIN_t pin,PIN_VAL_t* val);

#endif /* GPIO_H_ */
