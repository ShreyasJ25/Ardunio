
#include "source_header.h"
void (*interrupt_func)(void);

ISR(ADC_vect){
	interrupt_func();
	
}

void initialize_adc(){
	//ADMUX |=(1<<REFS1)|(1<<REFS0);   //2.56V INTERRNAL REFERENCE VOLTAGE
	ADMUX &= ~(1<<REFS1);
	ADMUX &= ~(1<<REFS0);  //AREF CONNECTION EXTERNAL
	ADCSRB &=~(1<<MUX5);
	ADMUX &=~(1<<MUX4);
	ADMUX &=~(1<<MUX3);
	ADMUX &=~(1<<MUX2);
	ADMUX &=~(1<<MUX1);
	ADMUX &=~(1<<MUX0);// taking input from adc0
	ADCSRA |=(1<<ADEN);  //WRITING 1 ENABLES ADC
	ADCSRA |=(1<<ADPS1)||(1<<ADPS0); //PRE-SCALAR SET TO 1
	
	ADCSRA |=(1<<ADIE);  // enabling the interrupt ADC Interrupt
	
	
	/*ADCSRA |=(1<<ADATE);
	ADCSRB &= ~(1<<ADTS0);
	ADCSRB &= ~(1<<ADTS1);
	ADCSRB &= ~(1<<ADTS2);  */    //testing free running mode
	
}

void initialize_uart(){
	
	int ubrr= (int)floor(((F_CPU /(16UL*(BAUD)))-1)); //formula to cal ubrr
	
	UBRR0L = ubrr & 0xff;  //ubrrl is first 8 lower bits of ubrr
	UBRR0H =  (ubrr >> 8); //ubrrl is first 4 higher bit numbers of ubrr
	
	UCSR0A &=  ~(1<<U2X0);   //2x speed is not used
	UCSR0B |= (1<<RXEN0); //ENABLING THE RECIEVER
	UCSR0B |= (1<<TXEN0);  //ENABLING THE TRANSMITTER
	UCSR0C |=(1<<UCSZ01)|(1<<UCSZ00);    //NOTE: FIRST ZERO FROM LEFT REPRESENT THE UART NUMBER LIKE 0,1,2,3
	
	UCSR0B &= ~(1<<UCSZ02) ;  // 011 SET  8-bit mode
	
	UCSR0C &= ~(1<<UMSEL01);    //  00 Setting it to asynchronous usart mode
	UCSR0C &=   ~(1<<UMSEL00);
	
	UCSR0C &= ~(1<<UPM01) ;
	UCSR0C &= ~(1<<UPM00);   // 00 MAKES THE PARITY DISABLED
	
	UCSR0C  &= ~(1<<USBS0);  // NUMBER OF STOP BITS IS 1
	UCSR0C  &=~(1<<UCPOL0);  //RISING CLK- TRANSMITTING   FALLING CLK- RECEIVED;
	
	}

void enable_adc_convertion(void){
	ADCSRA|=(1<<ADSC);
}

void attach_adc_interrupt(void (*func)()){
	
	interrupt_func =func;
}