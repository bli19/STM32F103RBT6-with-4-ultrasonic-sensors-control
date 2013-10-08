#ifndef _ultrasonic_H
#define _ultrasonic_H
#include"sys.h"



//------------------------------------------------------------移植修改区-----------------------------------------------------------------------

//U1
#define ULTRA_PORT	GPIOB
#define ULTRA_CLK       RCC_APB2Periph_GPIOB
#define ULTRA_TRIFOU			GPIO_Pin_1 /*PB */
#define ULTRA_ECHOFOU			GPIO_Pin_7 //is PB

#define ULTRA_TRIG			GPIO_Pin_5
#define ULTRA_ECHO			GPIO_Pin_6

//U2
#define ULTRA_C	  GPIOC
#define ULTRA_TCLK	    RCC_APB2Periph_GPIOC

#define ULTRA_TRITWO			GPIO_Pin_14
#define ULTRA_ECHOTWO			GPIO_Pin_15

//U3
#define ULTRA_A	  GPIOA
#define ULTRA_ACLK	    RCC_APB2Periph_GPIOA
#define ULTRA_TRITH			GPIO_Pin_5
#define ULTRA_ECHOTH			GPIO_Pin_3
//U4
//#define ULTRA_TRIFOU			GPIO_Pin_7 /*PB */
//#define ULTRA_ECHOFOU			GPIO_Pin_1 //is PB
// #define Touc_Bacy       GPIO_Pin_4
//U1
#define TRIG_Send  PBout(5)
#define ECHO_Reci  PBin(6)
// #define Touc_Bac   PBin(4)

//U2
#define TRITWO_Send  PCout(14)
#define ECHOTWO_Reci  PCin(15)

//U3
#define TRITH_Send  PAout(5)
#define ECHOTH_Reci  PAin(3)


//U4

#define TRIFOU_Send  PBout(1)
#define ECHOFOU_Reci  PBin(7)

//new touch sensor

#define Touc_Bacy       GPIO_Pin_4


//---------------------------------------------------------------------------------------------------------------------------------------------
void Ultran_Init(void);
void BounceBack(void);
void Ultra_Ranging(float *p);


void oater(float *q);

void eut(float *z);

void dakkfour(float *n);

void utouch(void);


#endif

