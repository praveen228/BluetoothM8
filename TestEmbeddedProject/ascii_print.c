#include <avr/io.h>

int main(void){
	unsigned char myList[] = "012345ABCD";
	unsigned char z;
	DDRB = 0xFF;
	while(1){
		for(z=0;z<10;z++){
			PORTB= myList[z];
		}
		z=0;	
		PORTB=0x00;
	}
	return 0;
}