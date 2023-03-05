#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

using namespace std;

typedef enum
{
	INPUT = 0,
	INPUT_PULLUP = 2,
	OUTPUT = 1
	
}pinDirection_t;

class pin
{
	private:
	volatile uint8_t *port_n, *dir_n,*pen_n;
	uint8_t pin_n;
	pinDirection_t dir;
	
	public:
	
	pin(volatile uint8_t *p, volatile uint8_t *q,volatile uint8_t* r,uint8_t s);
	void direction(pinDirection_t dir);
	void out(bool);
	void inp();
};
