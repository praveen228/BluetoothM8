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
	UBRRH = baud>>8;
	UBRRL = baud;
	UCSRB = (1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
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















#define F_CPU 16000000
#define LED_PIN 4
#define BAUD 9600
#include <avr/io.h>
#include <util/delay.h>
void USARTransmit(unsigned char);
void USARTInit(unsigned int);
void delay_1(unsigned int);
int main(void){
	USARTInit(9600);
	unsigned char i = 0x46;
	while(1){
		delay_1(50);
		i++;
		USARTransmit(i);
		delay_1(50);
		i++;
		USARTransmit(i);
	}
}
void USARTInit(unsigned int baud){
	UBRR0H = (unsigned char) (BAUD>>8);
	UBRR0H = (unsigned char) BAUD;
	//Enable Transmitter and Receiver
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//Set Frame format: 8data, 2 stop bit
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
void USARTransmit(unsigned char data){
	while(!(UCSR0A & (1 << UDRE0 ))){
		UDR0 = data;
	}
}
void delay_1(unsigned int del){
	if(del!=0){
		del--;
	}
}


