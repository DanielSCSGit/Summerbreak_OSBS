//	Author: Daniel Stojicic 
// 	Date:		23.06.2020
#include "main.h"
#include "forward_routine.h"

void forward(SPI_HandleTypeDef* hspi)
{
	uint8_t l6474_en = L6474_Enable;
	//Abfrage ob irgendwas schiefgelaufen ist (L6474 error)
	int FlagPinSet = 255;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_10) == 0)
	{
		FlagPinSet = 0;
	}
	// Reset, um die werte im L6474 auf die reset werte zu setzen 
	// dadurch ist keine init nötig 
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);	
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);	
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);	
	// CS
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET);	
	// Richtung forward setzen  
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);	
	// Senden des Enable befehls
	HAL_SPI_Transmit(hspi,&l6474_en,sizeof(uint8_t),HAL_MAX_DELAY);

}
