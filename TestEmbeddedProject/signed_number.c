#include <avr/io.h>

int main(void){
	char myNum[]={-4,-3,-2,-1,0,1,2,3,4};
	unsigned char z;
	DDRB = 0XFF;
	for(z=0;z<=8;z++)
		PORTB = myNum[z];
}