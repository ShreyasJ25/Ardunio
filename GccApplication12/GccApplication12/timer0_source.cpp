#include  "timer0_header.h"

void initialize_timer(){
	
	TCCR0A |= (1<<WGM00);
	TCCR0A |= (1<<WGM01);
	TCCR0B &= ~(1<<WGM02);  //SETTING TO FAST PWM
	
	TCCR0B |=(1<<CS00);
	TCCR0B |=(1<<CS02); //MAKING FREQUENCY DIVIDE BY 1024 TIMES i.e 15,625 Hz
	
	OCR0A = (uint8_t )250; //this is the value TCNT0 get compared to
	TCCR0A |=(1<<COM0A1);
	TCCR0A &=~(1<<COM0A0);  //  INVERTING MODE
	
	DDRB |=(1<<PB7); //OCOA IS PB7 i.e 13th pin ;you need to set it as out put
	
	//TIMSK0=(1<<OCIE0A);//enabling the interrupt when value in OCRA is equaled
	TIMSK0 =(1<<TOIE0); //enabling overflow interrupt
	
	
	//TCNT0 =0x00;
	//DDRB |=(1<<PB7); //setting internal led as output
}


ISR(TIMER0_OVF_vect){
	//PORTB |=(1<<PB7);
	OCR0A = 64;  //setting value to 64 everytime overflow happens so a same pwm wave is transmitted that has 25% duty cycle
	//count++;
	//count=count%4;
}


/*
// normAL interrupt

void initialize_timer(){
	
	TCCR0A &= ~(1<<WGM00);
	TCCR0A &= ~(1<<WGM01);
	TCCR0B &= ~(1<<WGM02);  //SETTING TO NORMAL OPERATION
	
	TCCR0B |=(1<<CS00);
	TCCR0B |=(1<<CS02); //MAKING FREQUENCY DIVIDE BY 1024 TIMES i.e 15,625 Hz
	
	//OCR0A = (uint8_t )64; //this is the value TCNT0 get compared to
	
	//TIMSK0=(1<<OCIE0A);//enabling the interrupt when value in OCRA is equaled 
	TIMSK0 =(1<<TOIE0); //enabling overflow interrupt
	
	TCNT0 =0x00;
	DDRB |=(1<<PB7); //setting internal led as output
	
}

ISR(TIMER0_COMPA_vect){	
}

ISR(TIMER0_OVF_vect){
	//PORTB |=(1<<PB7);
	count++;
	if(count==100){
		PORTB ^=(1<<PB7); //toggling led when overflow happens
		count=0;
	}
}

int main(void)
{
	sei();
	initialize_timer();
	TIFR0 |=(1<<TOV0);
	// PORTB &= ~(1<<PB7);
	
  
    while (1) 
    {
    }
	return 0;
}
*/
