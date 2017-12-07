#include <avr/io.h>
#include <avr/eeprom.h>

int main(void){
	while(1){
		while (EECR & (1<<EEWE));
		EEAR = 0x005F;
		EEDR = 0x44;
		EECR |=(1<<EEMWE);
		EECR |=(1<<EEWE);
	}
return 0;
}