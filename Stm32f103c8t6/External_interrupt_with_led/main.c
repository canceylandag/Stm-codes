#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "stm32f4xx.h"                  // Device header

void SystemClock_Config(void);
void gpioConfig(void);
void extiConfig(void);





int main(){
	
HAL_Init();
SystemClock_Config();
gpioConfig();	

	while(1){



}



}
void gpioConfig(){

	GPIO_InitTypeDef GPIOInitStructure;

	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIOInitStructure.Mode=GPIO_MODE_OUTPUT_PP;
	GPIOInitStructure.Pin=GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
	GPIOInitStructure.Pull=GPIO_NOPULL;
	GPIOInitStructure.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB,&GPIOInitStructure);
	
	GPIOInitStructure.Mode=GPIO_MODE_INPUT;
	GPIOInitStructure.Pin=GPIO_PIN_6;
	GPIOInitStructure.Pull=GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC,&GPIOInitStructure);
	
	
}

void extiConfig(){

	EXTI_InitTypeDef EXTIInitStructure;
	NVIC_InitTypeDefd NVICInitStructure;
	


}