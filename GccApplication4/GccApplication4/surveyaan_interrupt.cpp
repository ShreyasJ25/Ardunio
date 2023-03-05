#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "surveyaan_interrupt.h"

using namespace std;

/*void *custom_INT0(void);  //custom program passed by user to execute when INT0 occours; here used as shared variable
void *custom_INT1(void);
void *custom_INT2(void);
void *custom_INT3(void);
void *custom_INT4(void);
void *custom_INT5(void);
void *custom_INT6(void);
void *custom_INT7(void); */

void (*custom_INT[7])(void);
  //custom program passed by user to execute when INT0,INT1 ... INT7  occours; here used as shared variable
  
  
ISR(INT0_vect){
	(*custom_INT[0])();  //it can also be just    (* custom_INT0)();
	
}

ISR(INT1_vect){
	custom_INT[1]();
}
ISR(INT2_vect){
	custom_INT[2]();
}

ISR (INT3_vect){
	custom_INT[3](); 
}

ISR (INT4_vect){
	 custom_INT[4](); 
}
ISR (INT5_vect){
	 custom_INT[5]();
}
ISR (INT6_vect){
	 custom_INT[6]();
}
ISR (INT7_vect){
	custom_INT[7]();
}





void attach_int(uint8_t number, uint8_t typ, void (* funct)()){
	//interrupt number 0 to 7 which stands for INT0,INT1....INT7
	//interrupt type  RISING,FALLING,
	
	
	custom_INT[number]= funct;
	
	cli(); //include function to disable SREG
	
	
	if(number <=3){
		DDRD &=~(1<<number);  //setting the interrupt pin as input INT0 corresponds to PD0,INT1 corresponds to PD1
	}
	else{
		DDRE &=~(1<<number); //INT4 is connected to PE4 ...and INT7 is connected to PE7
	}
	
	EIMSK |=1<<number;  //enabling the interrupt
	
	if(number <=3)
	{   // number corresponds to INT0 to INT3)
		int num =number%4;
		switch(typ){
			case (RISING):
			EICRA |=((1<<(2*num)) |(1<<(2*num+1)));
			break;
			case(FALLING):
			EICRA |=(1<<(2*num+1));
			EICRA &= ~(1<<(2*num));
			break;
			case(LOW):
			EICRA &= ~(1<<(2*num));
			EICRA &= ~(1<<(2*num+1));
			break;
			default:
			EICRA &= ~(1<<(2*num+1));
			EICRA |= (1<<(2*num));
			break;
		}
	}
	
	else{
		int num =number%4;
		switch(typ){
			case (RISING):
			EICRB |=((1<<(2*num)) |(1<<(2*num+1)));
			break;
			case(FALLING):
			EICRB |=(1<<(2*num+1));
			EICRB &= ~(1<<(2*num));
			break;
			case(LOW):
			EICRB &= ~(1<<(2*num));
			EICRB &= ~(1<<(2*num+1));
			break;
			default:
			EICRB &= ~(1<<(2*num+1));
			EICRB |= (1<<(2*num));
			break;
		}
	}
	
	sei();  // to make SREG  7th bit to 1
	/* enabling the interrupt has to be at last */
}