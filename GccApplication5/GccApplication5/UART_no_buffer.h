# define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define BAUD 9600
#include <util/setbaud.h>

/*
FUNCTION:  void initialize(void)
DESCRIPTION: it initializes the uart 

FUNCTION:void attach_int_reciever(void (*fun1)())
DESCRIPTION:  it attaches receiver interrupt, the receiver interrupt is enabled when the device receives data from serial monitor
				user defined function func1 is executed when the interrupt occurs

FUNCTION:void attach_int_transmitter(void (*fun2)())
DESCRIPTION:  it attaches transmitter interrupt, the transmitter interrupt is enabled when the device transmits  data successfully to serial monitor,
				user defined function func2 is executed when the interrupt occurs		


*/
void initialize(void);

void attach_int_reciever(void (*fun1)());
void attach_int_transmitter(void (*fun2)());