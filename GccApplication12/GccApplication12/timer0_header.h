#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

/*
the timer0 here is set in PWM mode its duty cycle is set at 25% by having giving a value of 64 to OCR0A 64/255 =0.25
the value of timer can be changed at every overflow . For the purpose of testing  a single value is being considerd



*/

void initialize_timer();