
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
using namespace std;
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef enum
{
	INPUT = 0,
	INPUT_PULLUP = 2,
	OUTPUT = 1
	
}pinDirection_t;

class pin
{
	private:
	uint8_t *port_n, *dir_n;
	uint8_t pin_n;
	public:
	pinDirection_t dir;
	void direction(pinDirection_t dir);
	void out(bool val);
	uint8_t in();
};

void pin :: direction(pinDirection_t dir)
{
	uint8_t temp;
	switch(dir){
		case(0):
		
		temp = ~(1<<pin_n);
		*port_n = *port_n & temp;  //setting it to default 0
		*dir_n = *dir_n & temp;
		break;
		
		case(1):
		
		temp = (1<<pin_n);
		*dir_n = *dir_n | temp;
		temp = ~(temp);
		*port_n = *port_n & temp;   //setting it default to 0
		break;
		default:
		temp = (1<<pin_n);
		*port_n = *port_n | temp;    //when pulled up port is made 1 and dir is made zero
		temp = ~(temp);
		*dir_n = *dir_n & temp;
		break;
	}
}


void pin::out(bool val){
	switch(dir){
		case(0):
		port_n |= (val<<port_n);
		break;
		default:
		break;
		// cout<<"error";
	}
}
	uint8_t  pin::in(){
		switch(dir){
			case(1):
			uint8_t temp = port_n & (1<<port_n);
			temp>>port_n;
			return temp;
			
		}
		int main(void)
		{
			
		return 0;	
		}

