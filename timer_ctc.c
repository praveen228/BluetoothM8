#include <avr/io.h>

void delay_2(void);
int main(void){
	DDRB = 0xff;
	PORTB = 0x00;
	while (1){
		PORTB ^= 0xFF;
		delay_2();
	}
}

void delay_2(void){
	OCR0 = 0x7f;
	TCNT0 = 0x00;
	TCCR0 = 0b00001001;
	while((TIFR & (1<<OCF0)) == 0);
	TCCR0 = 0x0;
	TIFR = (1<<OCF0);
	OCR0 = 0x0;
}