#include "surveyaan_read_write.h"
using namespace std;


pin::pin(volatile uint8_t *p, volatile uint8_t *q,volatile uint8_t* r,uint8_t s){
	port_n = p;
	dir_n = q;
	pen_n= r;
	pin_n=s;
}

void pin :: direction(pinDirection_t dir)
{
	uint8_t temp;
	this->dir = dir;
	switch(dir){
		case(INPUT):
		
		temp = ~(1<<pin_n);
		*port_n = *port_n & temp;  //setting it to default 0
		*dir_n = *dir_n & temp;
		break;
		
		case(OUTPUT):
		
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


void pin::out(bool val)
{
	switch(dir)
	{
		case(OUTPUT):
		if (val){
		*port_n |= (val<<pin_n);}
		else{
			*port_n &=~(1<<pin_n);
		}
		break;
		default:
		// cout<<"error";
		break;
	}
}
 void pin::inp(void)
{
	if(this->dir == INPUT || this->dir == INPUT_PULLUP)
	{
		uint8_t ab = (*pen_n >>(pin_n)) & (0x01);
		/*DDRB |= 0b10000000;
		if(ab==1){
			PORTB|=0b10000000;
		}
		else{
			PORTB &=0b01111111;
		}*/
	}
	else
	{
		//cout<<"this is an output pin";
	}
}