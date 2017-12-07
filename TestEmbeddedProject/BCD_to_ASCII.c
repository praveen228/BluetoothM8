#include <avr/io.h>

int main(void){
	unsigned char temp= 0x47;
	unsigned char temp1,temp2;
	DDRC = 0xff;
	DDRB = 0xff;
	
	temp1 = 0x0f & temp;//low
	temp2 = temp>>4;//high
	
	temp1 = 0x30 | temp1;
	temp2 = 0x30 | temp2;
		
	PORTC = temp1;
	PORTB = temp2;
}