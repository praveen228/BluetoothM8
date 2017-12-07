#include <util/delay.h>
#include <avr/io.h>

int main(void){
	//Wrapper Function for porting code
	//Compiler optimizes - Shrinks delay -disable Optimization
	
	void delay_ms(int d){
		_delay_ms(d);
	}
	DDRB =0xFF;
	while(1){
		PORTB = 0xFF;
		delay_ms(10);
		PORTB = 0x55;
		delay_ms(10);
	}
	return 0;
}