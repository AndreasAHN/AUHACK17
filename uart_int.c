/*
 * uart.c
 *
 * Created: 28-11-2016 20:31:12
 *  Author: Asbjørn
 */ 

#include "uart_int.h"
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
 
void InitUART(unsigned long BaudRate, unsigned char DataBit, char Parity, unsigned char Rx_int){
	
	if(BaudRate < 300 || BaudRate > 115200 || DataBit < 5 || DataBit > 8){
		return;
	}
	else{
		UCSR0A = 0b00100000;
		UCSR0B = 0b00011000; // Enables RX and TX
		UCSR0C = 0b00000000;
				
		UBRR0 = (16000000 /(16 * BaudRate)) - 1; // Sets baud rate
		
		UCSR0C |= (DataBit - 5) << 1; // Sets the amount of data bits
		
		switch(Parity){
			case 'E':
				UCSR0C |= 0b10 << 4; // Parity even
				break;
			case 'O':
				UCSR0C |= 0b11 << 4; // Parity odd
				break;
		}
		
		if(Rx_int != 0){
			UCSR0B |= 1 << 7; // enable RX complete interrupt 0
		}
	}
	
	return;
}

unsigned char CharReady(){
	return (UCSR0A & (1 << 7));
}

char ReadChar(){
	while(!CharReady()){}
	return UDR0;
}

void SendChar(char Tegn){
	while((UCSR0A & (1 << 5)) == 0){
	}
	UDR0 = Tegn;
}

void SendString(char* Streng){
	while(*Streng != 0){
		SendChar(*Streng);
		Streng++;
	}
}

void SendInteger(int Tal){
	unsigned char integerArray [7] = {0};
	itoa(Tal, integerArray, 10);
	
	SendString(integerArray);
}
