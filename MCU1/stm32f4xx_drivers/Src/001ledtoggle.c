/*
 * 001ledtoggle.c
 *
 *  Created on: Jul 25, 2025
 *      Author: ASUS
 */

#include "stm32f407xx.h"

void delay(void)
{
	for(uint32_t i=0; i<500000;i++);
}

int main(void)
{
	GPIO_Handle_t ledpin;
	ledpin.pGPIOx = GPIOD;
	ledpin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	ledpin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	ledpin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_MED;
	ledpin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	ledpin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_PeriClkControl(GPIOD, ENABLE);
	GPIO_Init(&ledpin);
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}
	return 0;
}

