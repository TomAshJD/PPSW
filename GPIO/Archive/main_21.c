#include <LPC21xx.H>

#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

#define S0_bm 0x10
#define S1_bm 0x20
#define S2_bm 0x40
#define S3_bm 0x80


unsigned char ucLedIndeks = 1;


void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
};

void LedInit(){
  IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm;
  IO1SET = LED0_bm;
}



void LedOn(unsigned char ucLedIndeks){
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
	 case 4:
    break;
}
}


void KeyboardInit(){
	IO0CLR = S0_bm | S1_bm | S2_bm | S3_bm;
  IO0DIR &= ~(S0_bm | S1_bm | S2_bm | S3_bm);
}

enum KeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead(void) {
    if (!(IO0PIN & S0_bm))      
        return BUTTON_0;
    else if (!(IO0PIN & S1_bm)) 
        return BUTTON_1;
    else if (!(IO0PIN & S2_bm)) 
        return BUTTON_2;
    else if (!(IO0PIN & S3_bm))
        return BUTTON_3;
    else
        return RELEASED;
}

void LedButton1(){
	enum KeyboardState keyboardState = eKeyboardRead();
	
	switch (keyboardState) {
	case BUTTON_0: 
		IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
		LedOn(0); 
		break;
  case BUTTON_1: 
		IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
		LedOn(1); 
		break;
  case BUTTON_2: 
		IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
		LedOn(2); 
		break;
  case BUTTON_3: 
		IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
		LedOn(3); 
		break;
  case RELEASED: 
		IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
		LedOn(4); 
		break;  
        }
}

unsigned char ucCurrentLed = 0;

void StepLeft(void){
	ucCurrentLed = (ucCurrentLed+1)%4;
	LedOn(ucCurrentLed);
}

void StepRight(void){
	ucCurrentLed = (ucCurrentLed+3)%4;
	LedOn(ucCurrentLed);
}


int main() {
 LedInit();
 KeyboardInit();
 while(1){
  LedButton1();
	//StepRight(); 
	//Delay(1000);
 }
}
