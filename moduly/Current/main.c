#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
}


int main() {
 LedInit();
 KeyboardInit();
 while(1){
	Delay(100);
	switch (eKeyboardRead()) {
	 case BUTTON_1:  
		LedStepLeft();
		break;
	 case BUTTON_2:  
		LedStepRight();; 
		break;
	 default:
		break;
 }
}
}

