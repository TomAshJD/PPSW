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
 static eAutomatState eCurrentState = eSTOP;
 unsigned char static ucStepCounter=0;
 LedInit();
 KeyboardInit();
 while(1){
	Delay(100);
	switch (eCurrentState) {
	 case eSTOP:  
		if(eKeyboardRead() == BUTTON_0){
		eCurrentState = eRUNNING;
		ucStepCounter=0;
		}	
		break;
		
	 case eRUNNING:  
		if (ucStepCounter < 3) {
     LedStepRight();
     ucStepCounter++;
     } 
		 else if (ucStepCounter >= 3) {
      eCurrentState = eSTOP;
     }
     break;
 }
}
}

