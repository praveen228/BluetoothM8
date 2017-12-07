#include <avr/io.h>
#include <avr/eeprom.h>

int main(void){
	DDRB = 0xFF;
	while(1){
		
		while (EECR & (1<<EEWE));
		EEAR = 0x005F;
		EECR |=(1<<EERE);
		PORTB = EEDR;
	}
	return 0;
}