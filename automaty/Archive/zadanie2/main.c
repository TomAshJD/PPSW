#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
}

typedef enum {STATE0, STATE1, STATE2, STATE3, STATE4, STATE5} eAutomatState;

int main() {
 static eAutomatState eCurrentState = STATE0;
 LedInit();
 KeyboardInit();
 while(1){
	Delay(100);
	switch (eCurrentState) {
	 case STATE0:  
		LedStepLeft();
		eCurrentState = STATE1;
		break;
	 case STATE1:  
		LedStepLeft();
	  eCurrentState = STATE2;
		break;
	 case STATE2:  
		LedStepLeft();
	  eCurrentState = STATE3;
		break;
	 case STATE3:  
		LedStepRight();
	  eCurrentState = STATE4;
		break;
	 case STATE4:  
		LedStepRight();
	  eCurrentState = STATE5;
		break;
	 case STATE5:  
		LedStepRight();
	  eCurrentState = STATE0;
		break;
	 default:
		break;
 }
}
}

