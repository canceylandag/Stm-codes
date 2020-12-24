#include "stm32f10x.h"                  // Device header


void gpioConfig(){

	GPIO_InitTypeDef GPIOInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOInitStructure);
	
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_14;
	GPIO_Init(GPIOC,&GPIOInitStructure);
	
}

void extiConfig(){

	EXTI_InitTypeDef EXTIInitStructure;
	NVIC_InitTypeDef NVICInitStructure;
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource14);
	
	//External interrupt
	EXTIInitStructure.EXTI_Line=EXTI_Line14;
	EXTIInitStructure.EXTI_LineCmd=ENABLE;
	EXTIInitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTIInitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Init(&EXTIInitStructure);

		//NVIC Part
	
	NVICInitStructure.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVICInitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVICInitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVICInitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVICInitStructure);
	
	
}
void delay(uint32_t timee){

	while(timee>0){timee--;}
	
}

void EXTI15_10_IRQHandler(){

	if(EXTI_GetITStatus(EXTI_Line14)!=RESET){
	
		for(int i=0;i<4;i++){
		
		
		GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5);
		delay(3600000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_5);
		delay(3600000);
	}

	EXTI_ClearITPendingBit(EXTI_Line14);

}

}


int main(){
	gpioConfig();
	extiConfig();
	int ledarray[3]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_5};
	
	while(1){
	
	for(int i=0;i<3;i++){
	
	GPIO_SetBits(GPIOB,ledarray[i]);
		delay(3600000);
		GPIO_ResetBits(GPIOB,ledarray[i]);
		delay(3600000);
	
	}
	
	for(int i=1;i>=0;i--){
	
	GPIO_SetBits(GPIOB,ledarray[i]);
		delay(3600000);
		GPIO_ResetBits(GPIOB,ledarray[i]);
		delay(3600000);
	
	}
	
	
	}

}