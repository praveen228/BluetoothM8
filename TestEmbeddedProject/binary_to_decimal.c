#include <avr/io.h>

int main(void){
	unsigned char x, binbyte, d1,d2,d3;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	binbyte = 0xFD;
	x = binbyte / 10;
	d1 = binbyte % 10;
	d2 = x % 10;
	d3 = x / 10;
	
	PORTB = d1;
	PORTC = d2;
	PORTD = d3;
	
	return 0;
}