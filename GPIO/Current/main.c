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


void KeyboardInit(){
	IO0CLR = S0_bm | S1_bm | S2_bm | S3_bm;
  IO0DIR &= ~(S0_bm | S1_bm | S2_bm | S3_bm); //uzywamy iloczynu zeby miec pewnosc, ze interesujace nas bity sa ustawione na 0, które ustawia pin jako wejsciowy. 0x0001&0x0000 = 0x0000 podczas gdy 0x0001|0x0000 = 0x0001
}

enum KeyboardState {RELEASED,	BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

enum KeyboardState eKeyboardRead(void) {
    if ((IO0PIN & S0_bm)==0)      
        return BUTTON_0;
    else if ((IO0PIN & S1_bm)==0) 
        return BUTTON_1;
    else if ((IO0PIN & S2_bm)==0) // 0x40 0x0000
        return BUTTON_2;
    else if ((IO0PIN & S3_bm)==0) // 0x80 0x0000
        return BUTTON_3;
    else
        return RELEASED;
}



enum Directions {LEFT, RIGHT};

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

void LedMove(){
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


int main() {
 LedInit();
 KeyboardInit();
 while(1){
	Delay(100);
	LedMove();
}
}

