#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
/*
PB0 -D53- SS
PB1-D52-SCK
PB2-D51-MOSI
PB3- D50 -MISO
*/

void SPI_setup();

void enable_slave();