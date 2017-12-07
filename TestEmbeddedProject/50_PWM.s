.INCLUDE "M32DEF.INC"
.MACRO INITSTACK ;SETUP STACK
	LDI R20, HIGH(RAMEND)
	OUT SPH, R20
	LDI R20, LOW(RAMEND)
	OUT SPL, 20
.ENDMACRO
	INITSTACK
	LDI R16, 1<<5
	SBI DDRB, 5
	LDI R17,0
	OUT PORTB, R17
BEGIN: RCALL DELAY
	EOR R17, R16
	OUT PORTB, R17
	RJMP BEGIN
DELAY: LDI R20, 0xF2
	OUT TCNT0, R20
	LDI R20, 0x01
	OUT TCCR0, R20
AGAIN: IN R20, TIFR
	SBRS R20, TOV0
	RJMP AGAIN
	LDI R20, 0X00
	OUT TCCR0,R20
	LDI R20,(1<<TOV0)
	OUT TIFR, R20
	RET