#define F_CPU 16000000
#define BAUD 9600
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define N 100
#include <util/setbaud.h>

/*
PB0 -D53- SS
PB1-D52-SCK
PB2-D51-MOSI
PB3- D50 -MISO*/

using  namespace std;

void SPI_setup();

void initialize_uart();

void read_buff();