//power saving ;
#include "power_saving_header.h"

 /*
 after_sleep() function is treated as userdefined function which blinks the led.It is called soon after the system is woken up from sleep mode.
 
 In this program the system would go into sleep mode at initialize_necessary_sleep()  and the reduced power consumption can be observed using 
 ammeter. The system is awakened when a switch is pressed which is connected to INT0 . The user defined function  after_sleep()  is executed afer
 that and this process keeps repeating in a loop
 
 
 */
void after_sleep(){
	DDRB |=(1<<PB7);
	PORTB |=(1<<PB7);  //blinking led on off
	_delay_ms(2000);
	PORTB &=~(1<<PB7);
	_delay_ms(2000);
}

int main(void)
{ 
	
    
    while (1)   
    {  
		initialize_necessary_interrupt();
		
		initialize_necessary_sleep();
		
		after_sleep();

		
		detach_interrupt();  
		
		
    }
	return 0;
}

