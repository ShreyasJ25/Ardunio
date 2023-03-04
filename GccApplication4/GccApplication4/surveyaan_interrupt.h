#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//HAVE A SOURCE.cpp AND HEADER.h  FILE AND CALL THEM THROUGH main.cpp
//write a prog that enables a user defined or bespoke function upon enabling the interrupt

//have a function that disables the interrupts

//visit  https://exploreembedded.com/wiki/AVR_External_Interrupts
// visit  https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html





typedef enum{
	RISING=0,
	FALLING=1,
	LOW=2,
	ANY=3,
}typ;


/*
* Function Name
* Uses
* Return
* Description
*/

/*
* Function Name: attach_int
* Uses: attach_int(<interrupt number>, <interrupt trigger type>)
* Return: nothing
* Description: This function enables interrupt based on the argument passed. <interrupt number> represent INT0-7 
* and <interrupt trigger type> represents the FALLING/RISING/LEVEL/LOW trigger type.
*/
void attach_int(uint8_t, uint8_t, void (*funct)());