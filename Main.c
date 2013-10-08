//#include "LCD5110.h"
#include "ultrasonic.h"
#include "delay.h"
#include "lcd.h"
#include "ili9320.h"
#include "stdlib.h"
#include "stdio.h"
//#include "mpu6050.h"
//uint8_t DataBuffer[16];
int main()
{
	float temp;
	float yem;
	float sa;
	float sd;
	uint8_t NumA[16];
	uint8_t NumB[16];uint8_t NumC[16]; uint8_t NumD[16];
	

	//float y;//形参
	float treshold=1.0;
	SystemInit();
	delay_init(72);
	
	Ultran_Init();
	 ili9320_Initializtion();
  ili9320_Clear(Black);

	while(1)
	{
		
	Ultra_Ranging(&temp);
	eut(&sa);
  dakkfour( &sd);
		
 	
		// delay_ms(50);
     oater(&yem);   
		
 		delay_ms(50);
		
		
		

		
	//	if(sa<treshold || sd<treshold){
		//	ili9320_PutStr_16x24(0,90,"out of range",12,Black,Black);	
		
 		// sprintf((char*)DiNum," # Distance: %.3f", yem);
			sprintf((char*)NumA," # Distance: %.3f", sd);
 	ili9320_PutStr_16x24(0,60,NumA,18,Green,Black);
				sprintf((char*)NumB," # Distance: %.3f", sa);
 	ili9320_PutStr_16x24(0,90,NumB,18,Green,Black);
				sprintf((char*)NumC," # Distance: %.3f", temp);
 	ili9320_PutStr_16x24(0,120,NumC,18,Green,Black);
				sprintf((char*)NumD," # Distance: %.3f", yem);
 	ili9320_PutStr_16x24(0,150,NumD,18,Green,Black);
	 
// ili9320_PutStr_16x24(0,120,DisNum,18,Green,Black);		
			
		delay_ms(100);			
	//  }
	//	else
	// {
		 
 
	//	sd=0; 
	//	 yem=0; 
	//	 ili9320_PutStr_16x24(0,60,DisNum,18,Black,Black);	
 //	ili9320_PutStr_16x24(0,90,"out of range",12,Green,Black);	
 //  }
}
}




