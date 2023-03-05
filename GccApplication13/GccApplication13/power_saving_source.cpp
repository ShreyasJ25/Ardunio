#include "power_saving_header.h"

void enter_normal_mode();

ISR (INT0_vect){
	enter_normal_mode();
	//DDRB |=(1<<PB7);
	//PORTB |=(1<<PB7);
	_delay_ms(2000);
	// PORTB &=~(1<<PB7);
	_delay_ms(2000);
	//delay_ms(5000);
}

void intialize_power_saving(){
	SMCR &=~(1<<SM0);
	SMCR |=(1<<SM1);
	SMCR |=  (1<<SM2);
	
	//CSRA |= (1 << ADEN);//switching of adc
}
void enter_power_saving(){
	SMCR |=(1<<SE);
}
void intialize_interrupt(){
	EIMSK |=(1<<INT0);
	EICRA |=(1<<ISC00);
	EICRA |=(1<<ISC01);
	DDRD &=~(1<<PD0);
}
void detach_interrupt(){
	EIMSK &=~(1<<INT0);
}
void enter_normal_mode(){
	SMCR &=~(1<<SE);
}

void initialize_necessary_interrupt(){
	sei();
	intialize_interrupt();
}

void initialize_necessary_sleep(){
	intialize_power_saving();
	enter_power_saving();
	sleep_mode(); // this function is inbuilt function of sleep.h which initializes a bunch of assembly code that enables sleep
}