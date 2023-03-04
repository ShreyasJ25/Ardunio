#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

/*
function_name:initialize_necessary_interrupt()
working: it intializes necessary interrupt functions that are necessary for enabling INT0;
         also the interrupt conditions function are also defined

function_name:initialize_necessary_sleep()
working: it intializes necessary sleep functions that are necessary for enabling sleep;
           the initialization of sleep mode is done here. It is for now in standby ,but can be changed easily
		   Also a special call to assembly code is made which puts the system in sleep mode 



*/
void initialize_necessary_interrupt();


void initialize_necessary_sleep();

void detach_interrupt();