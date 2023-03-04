#include <avr/interrupt.h>
# define F_CPU 16000000UL
#include <util/delay.h>
#define N 100
#define BAUD 9600
#include <util/setbaud.h>

#include <avr/io.h>
using namespace std;

//void fun_rec_send();

  
  /*
  IN this program a uart receiver with buffer size of 100 is implemented
  whenever a long stream of data is given as an input from serial monitor,
  the data is temporarily stored in buffer and then later pushed on to serial monitor
  */
void initialize();