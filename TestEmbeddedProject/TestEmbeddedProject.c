#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define  cbi(SFR, BIT) (_SFR_BYTE(SFR) &= ~ _BV(BIT))
#define  sbi(SFR, BIT) (_SFR_BYTE(SFR) |=   _BV(BIT))
//BaudRate of HC-05 defaulting at 38400 -
#define F_CPU 16000000
#define RX_BUFFER_SIZE 128
#define BAUD 38400
#define BRC	((F_CPU/16/BAUD)-1)

char rxBuffer[RX_BUFFER_SIZE];
typedef enum {INIT,START,INTER,END} states;
states p_state,n_state;

unsigned int state_change=0;

uint8_t rxReadPos	=	0;
uint8_t rxWritePos	=	0;

char getChar(void);
char peekChar(void);

int main (void){
	
	UBRR0H = (BRC>>8);
	UBRR0L = BRC;
	
	UCSR0B |= (1 << RXEN0 ) | (1 << RXCIE0) | (1<<TXEN0);
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ01) ;
	
	DDRB = (1<<PORTB5);
	
	sei();
	p_state = INIT;
	n_state =INIT;
	
	while (1)	{
		char c = getChar();
		if (state_change!=0){
			switch (p_state)
			{	
				case INIT:
				cbi(PORTB,PORTB5);
				if (c=='1'){
					n_state = START;
					}else{
				n_state=INIT;}
				break;
				case START:
				if (c=='2')	{
					n_state = INTER;
				}
				else {n_state = INIT;}
				break;
				case INTER:
				if (c=='3')	{
					n_state = END;
				}
				else {n_state = INIT;}
				break;
				case END:
				if (c=='4'){
					n_state = INIT;
					UDR0 = 'Y';
					}else{
				n_state =INIT;}
				break;
			}
			p_state = n_state;
			state_change = 0;
		}
		
	}
	return 0;
}
char peekChar(void){
	char ret = '\0';
	if (rxReadPos != rxWritePos){
		ret = rxBuffer[rxReadPos];
	}
	return ret;
}
char getChar(void){
	char ret = '\0';
	if (rxReadPos != rxWritePos){
		ret = rxBuffer[rxReadPos];
		rxReadPos++;
		state_change++;
		if (rxReadPos >= RX_BUFFER_SIZE)
		{
			rxReadPos = 0;
		}
	}
	return ret;
}
ISR(USART_RX_vect){
	//Reads data when data written to 
	rxBuffer[rxWritePos] = UDR0;
	//Echo's lines to terminal
	UDR0 = rxBuffer[rxWritePos];
	rxWritePos++;
	if (rxWritePos >= RX_BUFFER_SIZE)
	{
		rxWritePos = 0;
	}

}

