#include <avr/io.h>
#include <avr/interrupt.h>
#define  cbi(SFR, BIT) (_SFR_BYTE(SFR) &= ~ _BV(BIT))
#define  sbi(SFR, BIT) (_SFR_BYTE(SFR) |=   _BV(BIT))

#define F_CPU		16000000
#define BAUD	9600
#define BRC		((F_CPU/16/BAUD)-1)

#define  RX_BUFFER_SIZE	128

char rxBuffer[RX_BUFFER_SIZE];
uint8_t rxReadPos	=	0;
uint8_t rxWritePos	=	0;

char getChar(void);
char peekChar(void);

int main (void){
	UBRR0H = (BRC>>8);
	UBRR0L = BRC;
	
	UCSR0B = (1 << RXEN0) | (1 << RXCIE0);
	UCSR0C = (1 << UCSZ01)| (1 << UCSZ00);
	
	DDRB = (1<<PORTB0);
	
	sei();
	
	while (1)	{
		char c = getChar();
		if(c == '1'){
			sbi(PORTB, PORTB0);
		}
		else if (c == '0')
		{
			cbi(PORTB,PORTB0);
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
		if (rxReadPos >= RX_BUFFER_SIZE)
		{
			rxReadPos = 0;
		}
	}
	return ret;
}
ISR(USART_RX_vect){
	rxBuffer[rxWritePos] = UDR0;
	rxWritePos++;
	if (rxWritePos >= RX_BUFFER_SIZE)
	{
		rxWritePos = 0;
	}
}