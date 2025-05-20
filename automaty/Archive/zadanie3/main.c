#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
}

typedef enum {eLedMoveLeft, eLedMoveRight} eAutomatState;

int main() {
 static eAutomatState eCurrentState = eLedMoveLeft;
 unsigned char static ucMoveCounter=0;
 LedInit();
 KeyboardInit();
 while(1){
	Delay(500);
	switch (eCurrentState) {
	 case eLedMoveLeft:  
		LedStepLeft();
		ucMoveCounter++;
		if(ucMoveCounter > 2){
			eCurrentState = eLedMoveRight;
		}
		break;
	 case eLedMoveRight:  
		LedStepRight();
	  ucMoveCounter--;
		if (ucMoveCounter < 1){
			eCurrentState = eLedMoveLeft;
		}
		break;
	 default:
		break;
 }
}
}

