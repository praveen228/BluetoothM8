#include <avr/io.h>

int main(void){
	unsigned char mydata[]={0x25,0x62,0x3F,0x51,0xE8};
	unsigned char x;
	unsigned char chksumbyte=0;
	
	DDRD = 0xFF;
	
	for(x=0;x<5;x++){
		chksumbyte = chksumbyte + mydata[x];
	}
	if (chksumbyte == 0){
		PORTD = 'G';
		}else{
		PORTD = 'B';
	}	
}