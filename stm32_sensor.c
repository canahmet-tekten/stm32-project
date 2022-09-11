#include "stm32f10x.h"           //Device header
#include "stm32f10x_gpio.h"		//Keil::Device:StdPeriph Drivers:GPIO

float distance:0;
	
void gpioConfig(){
	
	GPIO_InitTypeDef GPIOInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//TRIG PIN CONFİG
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIOInitStructure);
	
	//ECHO PIN CONFİG
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIOInitStructure);
	
	
}

void delayUS(uint32_t time){
	uint32_t newTime=time*24;
	while(newTime--);
}

float HCSR04_Read(){
	uint32_t time=0;
	float tempDistance=0;
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	delayUS(10);
	GPIO_Setbits(GPIOA,GPIO_Pin_1);
	delayUS(10);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	delayUS(10);
	
	while(!(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)));
	
	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0){
		time++;
		delayUS(1);
		
	}
	
	tempDistance=(float)time/58;
	if(tempDistance>400){
		*
		*
	}
	delayUS(1000);
	
	return tempDistance;


int main(){
	gpioConfig();
	
	while(1){
		
		distance=HCSR04_Read();
	}
}