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
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0x00;	PORTB = 0xFF;
	DDRC = 0xFF;	PORTC = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char i = 0;
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	for(i = 0; i <= 7; ++i){
		if(tmpA && 0x01){
			tmpC = tmpC + 1;
		}
		if(tmpB && 0x01){
			tmpC = tmpC + 1;
		}
		tmpA = tmpA >> 1;
		tmpB = tmpB >> 1;
	}
	PORTC = tmpC;		
    }
    return 1;
}
