#include "spi_master_header.h"
//master SPI



void send_data(){

	char  ab[]="data sending NO MORE THAN 50 CHARS WHY because i am not sure of why or whsy not\n";
	int  num = sizeof(ab)/sizeof(char)-1;
			
	for(int i=0;i<num;i++)
	{
		SPDR = ab[i];
		while(!(SPSR & (1<<SPIF)));
		
			_delay_us(100)	; //for the sake of 9600baudrate used for c++ code written . not required for ardunio code
	}
	_delay_ms(1000);
		
	
}




int main(void)
{
	SPI_setup();
	
	enable_slave();
    /* Replace with your application code */
    while (1) 
    {
		send_data();
    }
	
	return 0;
}

