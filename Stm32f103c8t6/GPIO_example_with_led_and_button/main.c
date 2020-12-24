#include "stm32f10x.h"                  // Device header


void gpioConfig(){


	GPIO_InitTypeDef GPIOInitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6|GPIO_Pin_7;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIOInitStructure);
	
}

void delay(uint32_t timee){

	while(timee--);
}

int main(){

		gpioConfig();
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
while(1){
	GPIO_ResetBits(GPIOA,GPIO_Pin_2|GPIO_Pin_3);
	
	int but_dur=GPIO_ReadOutputData(GPIOA)& GPIO_Pin_6; 	
	if(but_dur==0){
	
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
	}else{
	
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	}

}
}