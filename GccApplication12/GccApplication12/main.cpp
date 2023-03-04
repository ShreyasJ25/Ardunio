
//timer0
#include "timer0_header.h"



int main()
{
	DDRB |=(1<<PB7);
	PORTB |=(1<<PB7);
	_delay_ms(3000);
	sei();    //enabling global interrupt i.e SREG
	initialize_timer();
	
	
	
	while (1)
	{ 
		
	}
	return 0;
}