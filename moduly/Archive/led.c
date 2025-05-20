#include <LPC21xx.H>
#include "led.h"
#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

unsigned char ucLedIndeks = 1;

void LedInit(){
  IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  switch (ucLedIndeks){
   case 0:
    IO1SET = LED0_bm;
    break;
   case 1:
    IO1SET = LED1_bm;
    break;
   case 2:
    IO1SET = LED2_bm;
    break;
   case 3:
    IO1SET = LED3_bm;
}
}

void LedStep (enum Directions eDirection){
	static unsigned char sucCurrentLed = 0;
	switch(eDirection){
	case LEFT: 
		sucCurrentLed++;
		break;
	case RIGHT: 
		sucCurrentLed--;
		break;
	default:
		break;
}
	LedOn(sucCurrentLed%4);
}


void LedStepLeft(void){
	LedStep(LEFT);
}

void LedStepRight(void){
	LedStep(RIGHT);
}


