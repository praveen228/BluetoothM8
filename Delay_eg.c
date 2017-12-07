#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>

int main(void){
	DDRB = 0xff;
	while(1){
		PORTB ^= (1<<5);  1
		_delay_ms(2000);
	}
}

udr0

&
0000 0000  0000 0001 0 
0000 0001  0000 0001 1

port b

0000 0000 