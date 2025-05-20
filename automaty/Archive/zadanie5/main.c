#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
}

typedef enum {eSTOP, eRUNNING} eAutomatState;

int main() {
 static eAutomatState eCurrentState = eRUNNING;
 LedInit();
 KeyboardInit();
 while(1){
	Delay(100);
	switch (eCurrentState) {
	 case eSTOP:  
		if(eKeyboardRead() == BUTTON_1){
		eCurrentState = eRUNNING;
		}	
		break;
		
	 case eRUNNING:  
		if (eKeyboardRead() == BUTTON_0) {
     eCurrentState = eSTOP; 
     } 
		 else {
      LedStepRight();
     }
     break;
 }
}
}

