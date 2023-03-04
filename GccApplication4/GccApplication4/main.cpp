/*
 * GccApplication4.cpp
 *
 * Created: 30-01-2023 19:03:45
 * Author : shreyas
 */ 

#include "surveyaan_interrupt.h"
using namespace std;
void fun1(void ){
	DDRB |=0b10000000;
	PORTB |=0b10000000;
	
}

void fun0(void ){
	DDRB |=0b10000000;
	PORTB &=~(1<<7);
	
}

int main(void)
{   
/*	DDRB|=0b10000000;
	DDRD &=0B00000000; //MAKING PD0 AND PD1 AS INPUT
	
	
	PORTB |=(1<<PB7);
	EIMSK |=((1<<INT0)|(1<<INT1)); //ENABLING THESE TWO INTERRUPT;
	EICRA |=(1<<ISC01);
	EICRA &=~(1<<ISC00); //FALLING EDGE  10
	EICRA |=((1<<ISC11)|(1<<ISC10)); //RISING EDGE
	
	sei(); // to do this  SREG |=(1<<7);  */



 attach_int(0,FALLING,&fun0);
 attach_int(1,RISING,&fun1);
 
	
	while(1)
	{
		_delay_ms(1000);
	}
	
 
    return 0;
}


