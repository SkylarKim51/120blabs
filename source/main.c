/*	Author: skim370
 *  Partner(s) Name: 
 *	Lab Section:023
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00;	PORTA = 0xFF;
	DDRC = 0xFF;	PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char maskA = 0x00;
    while (1) {
	tmpA = PINA;
	maskA = tmpA;
	if( (maskA & 0x0F) >= 0x01){
		tmpC = 0x20;
	}
	maskA = tmpA;
	if((maskA & 0x0F) >= 0x03){
		tmpC = 0x30;
	}
	maskA = tmpA;
	if((maskA & 0x0F) >= 0x05){
		tmpC = 0x38;
	}
	maskA = tmpA;
	if((maskA & 0x0F) >= 0x07){
		tmpC = 0x3C;
	}
	maskA = tmpA;
	if((maskA & 0x0F) >= 0x0A){
		tmpC = 0x3E;
	}
	maskA = tmpA;
	if((maskA & 0x0F) >= 0x0D){
		tmpC = 0x3F;
	}
	maskA = tmpA;
	if((maskA & 0x0F) <= 0x04){
		tmpC = tmpC | 0x40;
	}
	maskA = tmpA;
	if((maskA & 0x70) == 0x30){
		tmpC = tmpC | 0x80;
	} 
	PORTC = tmpC;
	tmpA = 0;
	tmpC = 0;
	maskA = 0;
}
    return 1;
}
