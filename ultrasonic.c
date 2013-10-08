#include "stm32f10x.h"
#include "ultrasonic.h"
#include "delay.h"
#include "lcd.h"
#include "ili9320.h"
/********************************************************************************************************************************************
@f_name: void Ultran_Init(void)
@brief:	 超声波硬件模块初始化
@param:	 None
@return: None
*********************************************************************************************************************************************/
void Ultran_Init(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(ULTRA_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin =ULTRA_TRIG|ULTRA_TRIFOU;       //TRIG
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//PUSH pull
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(ULTRA_PORT,ULTRA_TRIG);
  GPIO_ResetBits(ULTRA_PORT,ULTRA_TRIFOU);
 	GPIO_InitStructure.GPIO_Pin =ULTRA_ECHO |ULTRA_ECHOFOU;		//echo back
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//floating input
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);	
	
	RCC_APB2PeriphClockCmd(ULTRA_TCLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =ULTRA_TRITWO;       
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 	GPIO_Init(ULTRA_C, &GPIO_InitStructure);
	GPIO_ResetBits(ULTRA_C,ULTRA_TRITWO);

	GPIO_InitStructure.GPIO_Pin =ULTRA_ECHOTWO;		
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 	GPIO_Init(ULTRA_C, &GPIO_InitStructure);	
	
	RCC_APB2PeriphClockCmd(ULTRA_ACLK, ENABLE);
		GPIO_InitStructure.GPIO_Pin =ULTRA_TRITH;       
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 	GPIO_Init(ULTRA_A, &GPIO_InitStructure);
	GPIO_ResetBits(ULTRA_A,ULTRA_TRITH);

	GPIO_InitStructure.GPIO_Pin =ULTRA_ECHOTH;		 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 	GPIO_Init(ULTRA_A, &GPIO_InitStructure);	
	
	
// 	GPIO_InitStructure.GPIO_Pin =Touc_Bacy;		//Capacitive sensor control
//  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
//  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//keep it floating
//  	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);	
}
//
//
// void BounceBack(void){
// 	float x;
// 	char DisNum[16];
// 	while(!Touc_Bac){

//     x=0 ;
//    sprintf((char*)DisNum,"Bounce: %f", x);
// 		ili9320_PutStr_16x24(0,60,DisNum,10,Green,Black);
//   }
// 	 while(Touc_Bac){
//     x=1;
//    sprintf((char*)DisNum,"Bounce: %f", x);
// 		ili9320_PutStr_16x24(0,60,DisNum,10,Green,Black);
//   }		

// }
//
//
/********************************************************************************************************************************************
@f_name: void Ranging(void)
@brief:	 average 5 measurements
@param:	 float *p
@return: None
*********************************************************************************************************************************************/
// void Ultra_Ranging(float *p)
// {
// 	u8 i;
// 	u32 j;
// 	float Ultr_Temp;	
// 	for(i=0;i<5;i++)
// 	{
// 		TRIG_Send=1;
// 		delay_ms(10);
// 		TRIG_Send=0;
// 		while(!ECHO_Reci);
// 		while(ECHO_Reci)
// 		{
// 			delay_us(8);
// 			j++;
// 		}
// 		Ultr_Temp+=340/2*j*10;//   
// 		j=0;
// 		delay_ms(60);// 
// 	}
// 	*p=Ultr_Temp/5/1000000; // 	
// }
//8491

void Ultra_Ranging(float *p)
{
	u8 i;
	u32 j;
	float Ultr_Temp;	
	for(i=0;i<5;i++)
	{
		TRIG_Send=1;
// 		TRITWO_Send=1;
// 		TRITH_Send=1;
// 		TRIFOU_Send=1;
		
		delay_ms(10);
		TRIG_Send=0;
	//	TRITWO_Send=0;
// 		TRITH_Send=0;
// 		TRIFOU_Send=0;
		
		while((!ECHO_Reci));//&&(!ECHOTWO_Reci)&&(!ECHOTH_Reci)&&(!ECHOFOU_Reci)
		while(ECHO_Reci)//&&ECHOTWO_Reci&&ECHOTH_Reci&&ECHOFOU_Reci
		{
			delay_us(8);
			j++;
		}
		Ultr_Temp+=340/2*j*10;//
		j=0;
		delay_ms(60);//
	}
	*p=Ultr_Temp/5/1000000; //
}



void oater(float *q)
{
	u8 b;
	u32 k;
	float Ul_Temp;	
	for(b=0;b<5;b++)
	{
//		TRIG_Send=1;
 		TRITWO_Send=1;
// 		TRITH_Send=1;
// 		TRIFOU_Send=1;
		
		delay_ms(10);
//		TRIG_Send=0;
		TRITWO_Send=0;
// 		TRITH_Send=0;
// 		TRIFOU_Send=0;
		
		while((!ECHOTWO_Reci));//&&(!ECHOTWO_Reci)&&(!ECHOTH_Reci)&&(!ECHOFOU_Reci)
		while(ECHOTWO_Reci)
		{
			delay_us(8);
			k++;
		}
		Ul_Temp+=340/2*k*10;
		k=0;
		delay_ms(60);
	}
	*q=Ul_Temp/5/1000000;
}





void eut(float *z){
	
	u8 one;
	u32 te;
	float ptf;	
	for(one=0;one<5;one++)
	{
 
 		TRITH_Send=1;
// 		TRIFOU_Send=1;
		
		delay_ms(10);
 
		TRITH_Send=0;
// 		TRIFOU_Send=0;
		
		while((!ECHOTH_Reci));//&&(!ECHOTWO_Reci)&&(!ECHOTH_Reci)&&(!ECHOFOU_Reci)
		while(ECHOTH_Reci)
		{
			delay_us(8);
			te++;
		}
		ptf+=340/2*te*10;
		te=0;
		delay_ms(60);//
	}
	*z=ptf/5/1000000; //
	

}


void dakkfour(float *s){

	u8 i;
	u32 j;
	float ul;	
	for(i=0;i<5;i++)
	{
		TRIFOU_Send=1;
		delay_ms(10);
		TRIFOU_Send=0;
		while(!ECHOFOU_Reci);
		while(ECHOFOU_Reci)
		{
			delay_us(8);
			j++;
		}
		ul+=340/2*j*10;//
		j=0;
		delay_ms(60);// 
	}
	*s=ul/5/1000000; //
}


void utouch(){



}



