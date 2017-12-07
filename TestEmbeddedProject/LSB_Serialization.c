#include <avr/io.h>
//LSB Serialization
#define serPin 3
#define serOut 2

int main(void){
	unsigned char conbyte = 0x44;
	unsigned char regALSB;
	unsigned char x=0;
	regALSB = conbyte;
	
	DDRC |= (1<<serPin) | (1<<serOut);
	for (x=0;x<8;x++){
		if (regALSB & 0x01){
			PORTC|= (1<<serPin);
		}
		else{
			PORTC&= ~(1<<serPin);
		}
		regALSB = regALSB >> 1;
	}
}