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
  IO1CLR = LED0_bm | LED1_bm | LED1_bm | LED1_bm;
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
    break;
}
}

enum ButtonState{RELEASED, PRESSED};

enum ButtonState ReadButton1(){
	if (IO0PIN & S0_bm){
		return RELEASED;
	}
	else {
		return PRESSED;
	}
}

void LedButton1(){
	enum ButtonState buttonState = ReadButton1();
	
	switch(buttonState){
		case PRESSED:
			IO1SET = LED1_bm;
			IO1CLR = LED0_bm;
			break;
		case RELEASED:
			IO1SET = LED0_bm;
			IO1CLR = LED1_bm;
			break;
		default:
			break;
}
}

int main() {
 LedInit();
 while(1){
  LedButton1();
 }
}
