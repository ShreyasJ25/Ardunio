#include "UART_no_buffer.h"

void (*f1)(void);
void (*f2)(void);

ISR(USART0_RX_vect){

	UCSR0B &= ~(1<<RXCIE0);
	DDRB |=0b10000000;
	PORTB &=0b01111111;
	
	f1();
	
	_delay_ms(1000);
	PORTB |=0b10000000;
	UCSR0B |= (1<<RXCIE0);
	
}



ISR(USART0_TX_vect){
	
	UCSR0B &= ~(1<<TXCIE0);
	DDRB |=0b10000000;
	PORTB &=0b01111111;
	while(!(UCSR0A>>5 & 0x01));
	UDR0 = (uint8_t)'\n';
	_delay_ms(2000);
	
	f2();
	
	PORTB |=0b10000000;
	UCSR0B |= (1<<TXCIE0);

}

void attach_int_reciever(void (*fun1)()){
	f1 =fun1;
}

void attach_int_transmitter(void (*fun2)()){
	f2=fun2;
}

void initialize(){
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
	
	
	UCSR0B |=(1<<TXCIE0);    //ENABLING TRANSMITTING INTERUPT
	UCSR0B |=(1<<RXCIE0);
	
}