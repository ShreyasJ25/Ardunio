
//slave spi
#include "spi_slave_header.h"

int main(void) 
{
	sei();
	
	initialize_uart();
	SPI_setup();
	/* Replace with your application code */
	while (1)
{
	read_buff();
	}
	return 0;
}

