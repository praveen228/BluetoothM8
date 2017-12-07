#include <avr/io.h>
#define serPin 3
int main(void){
	unsigned char temp,x;
	unsigned char REGSER;
	DDRC &= ~(1<<serPin);
	
	for(x=0;x<8;x++){
		REGSER = REGSER >> 1;
		REGSER |= (PINC &(1<<serPin))<<(7-serPin);
	}
	return 0;
	
}