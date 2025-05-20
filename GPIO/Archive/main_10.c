#include <LPC21xx.H>
#define LED0_bm 0x10000
#define LED3_bm 0x80000

void Delay(int iDelay){
	
 int iDelayCounter;
	
 for(iDelayCounter = iDelay*12000; iDelayCounter>0; iDelayCounter--){
}
};

int main() {
 IO1DIR = LED3_bm;
 while(1){
  IO1SET = LED3_bm;
  Delay(20);
  IO1CLR = LED3_bm;
	Delay(20);
 }
}
