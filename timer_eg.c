#include <avr/io.h>
void delay_1(void);
int main(void){
	DDRB = 0xFF;
	PORTB
	while(1){
		PORTB = 0xff;
		delay_1();
		PORTB = 0x00;
		delay_1();
	}
}

void delay_1(){
	
	TCNT0 = 0xFA; // Counter Register
	TCCR0 = 0x01; //Enable Timer 1
	while ((TIFR & (1<<TOV0)) == 0 ); //Wait until Overflow flag is set
	TCCR0=0; //Stop the timer
	TIFR = 0x01; //clear Tov0;
	
}