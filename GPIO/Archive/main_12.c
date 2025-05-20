#include <LPC21xx.H>
#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
};

int main() {
	
 while(1){
	IO1DIR = LED0_bm;
	IO1SET = LED0_bm;
	Delay(250);
	IO1CLR = LED0_bm;
	
	IO1DIR = LED1_bm;
	IO1SET = LED1_bm;
	Delay(250);
	IO1CLR = LED1_bm;
	 
	IO1DIR = LED2_bm;
	IO1SET = LED2_bm;
	Delay(250);
	IO1CLR = LED2_bm;
	
	IO1DIR = LED3_bm;
	IO1SET = LED3_bm;
	Delay(250);
	IO1CLR = LED3_bm;
	 
	IO1DIR = LED2_bm;
	IO1SET = LED2_bm;
	Delay(250);
	IO1CLR = LED2_bm;
	
	IO1DIR = LED1_bm;
	IO1SET = LED1_bm;
	Delay(250);
	IO1CLR = LED1_bm;
	
 }
}
