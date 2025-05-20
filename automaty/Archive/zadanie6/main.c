#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
}

typedef enum {eLED_LEFT, eLED_RIGHT, eSTAND_STILL} eAutomatState;

int main() {
 static eAutomatState eCurrentState = eSTAND_STILL;
 LedInit();
 KeyboardInit();
 while(1){
	Delay(100);
	switch (eCurrentState) {
	 case eSTAND_STILL:  
		if(eKeyboardRead() == BUTTON_0){
		eCurrentState = eLED_LEFT;
		}	
		else if (eKeyboardRead() == BUTTON_2){
		eCurrentState = eLED_RIGHT;
		}
		break;
		
	 case eLED_LEFT:  
		if (eKeyboardRead() == BUTTON_1) {
     eCurrentState = eSTAND_STILL; 
     } 
		 else {
      LedStepLeft();
     }
     break;
		 
	 case eLED_RIGHT:  
		if (eKeyboardRead() == BUTTON_1) {
     eCurrentState = eSTAND_STILL; 
     } 
		 else {
      LedStepRight();
     }
     break;
 }
}
}

