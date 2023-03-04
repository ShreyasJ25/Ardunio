#include <avr/io.h>
# define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>
#define BAUD 9600
#include <util/setbaud.h>
/*
FUNCTION: intialize_adc() 
DESCRIPTION: it initializes registers concerning adc

FUNCTION: intialize_uart()
DESCRIPTION: it initializes registers concerning uart which would be monitored by serial monitor

FUNCTION: void enable_adc_convertion(void)
DESCRIPTION: It enables the adc to start conversion

FUNCTION:  void  attach_adc_interrupt(void (*func)())
DESCRIPTION: it attaches a adc_interrupt, the pointer passed is a pointer to a user defined function that would be spawned
				as soon as ADC conversion happens and is ADC data registers are overwritten 


*/
void initialize_adc();

void initialize_uart(void);

void enable_adc_convertion(void);

void attach_adc_interrupt(void (*func)());





