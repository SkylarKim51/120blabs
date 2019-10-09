/*	Author: skim370
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRB = 0x00;	PORTB = 0xFF;
	DDRC = 0xFF;	PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char readA = 0x00;
	unsigned char readB = 0x00;
	unsigned char i = 0;
    while (1) {
	readA = PINA;
	readB = PINB;
	tmpA = readA;
	tmpB = readB;
	for(i = 0; i <= 7; ++i){
		tmpA = readA >> i;
		tmpB = readB >> i;
		if((tmpA & 0x01) == 0x01){
			tmpC = tmpC +1;
		}
		if((tmpB & 0x01) == 0x01){
			tmpC = tmpC +1;
		}
	}
	PORTC = tmpC;
	tmpA = tmpB = tmpC = readA = readB= 0x00;			
    }
    return 1;
}
