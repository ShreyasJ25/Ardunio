#include "spi_master_header.h"
void SPI_setup()
{
	
	SPCR |=(1<<SPE)|(1<<MSTR); //ENABLING THE SPI AND SETTING IT AS MASTER
	SPCR &= ~(1<<CPOL); //LEADING EDGE :RISING   TRAILINGEDGE :FALLING
	SPCR &= ~(1<<CPHA);  // LEADING EDGE:SAMPLE    TRAILING EDGE:SETUP
	SPCR |= (1<<SPR0);  //SCK = Fosc/16 ;
	
	
	DDRB = 0x00;
	DDRB |=(1<<PB0);  //SETTING SS AS OUTPUT
	DDRB |=(1<<PB1);  //SETTING SCK AS OUTPUT
	DDRB |=(1<<PB2);
	
	PORTB |=(1<<PB0); //SETTING SS HIGH AS IT SHOULD BE DISABLED
}

void enable_slave(){
	PORTB &=~(1<<PB0);//enable the ss by pulling it to zero
}