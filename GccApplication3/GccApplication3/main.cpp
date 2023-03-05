#include "surveyaan_read_write.h"
using namespace std;
	
int main(void)
{
	
	pin cb(&PORTB,&DDRB,&PINB,6);
	cb.direction(INPUT);
	
	while(1){
		
			cb.inp();
			_delay_ms(1000);
			
		}
	
	
	
  /*
  //DDRB |= 0b10000000;
  //uint8_t s = 0x04;
  pin cb(&PORTB,&DDRB,6);
	cb.direction(OUTPUT); 
	
	while(1){
		
	cb.out(false);
	//PORTB = 0x00;
	_delay_ms(3000);                 //using for out
	//cb.out(true);
    PORTB = 0xff;
	_delay_ms(3000);
	}
	*/		
	return 0;			
}







