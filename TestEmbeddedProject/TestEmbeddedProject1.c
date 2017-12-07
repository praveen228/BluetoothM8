/*
 * TestEmbeddedProject.c
 *
 * Created: 24-04-2016 22:54:12
 *  Author: PRAVEEN
 System Clock     : 8MHz
 USART Baud Rate  : 9600
 USART Stop Bits  : 1
 USART Mode       : Asynchronous Mode
 USART Parity     : NO parity
 */ 


#include <avr/io.h>
#include <stdio.h>
#define F_CPU 8000000
void USARTinit(unsigned int);
void USARTtransmit(unsigned char);
void delay(unsigned int);
int main(void)
{
	unsigned char i=0;
	USARTinit(9600);
    while(1)
    { 
		delay(1);
		i++;
		USARTtransmit(i);
		delay(1);
		i++;
		USARTtransmit(i);
    }
}

void USARTinit(unsigned int baud){
	unsigned int j=5;
	UBRRH = baud>>8;
	UBRRL = baud;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	printf("Value of j: %i",j);
	
}
void delay(unsigned int del){
	if(del != 0){
		del--;
	}
}
void USARTtransmit(unsigned char data){
	//UCSRA = 0x00;
	while( !(UCSRA & (1<<UDRE) ) ){
		
		UDR = data;	
	}
	
}
