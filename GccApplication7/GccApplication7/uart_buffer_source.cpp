#include "uart_buffer_header.h"
uint8_t rec_arr[N];
uint16_t ri=0,rj=0;
void read_buff();

ISR(USART0_RX_vect){
	//cli();
	//UCSR0B &= ~(1<<RXCIE0);
	rec_arr[rj++]= UDR0;
	rj = rj%N;
	if(rj==ri)ri++;
	
	read_buff();
}
		
void read_buff(){
	
	if(ri!=rj){
	while(!(UCSR0A>>5 & 0X01));
	UDR0 = (uint8_t) rec_arr[ri];   //data
	ri++;
	/*while(!(UCSR0A>>5 & 0X01));
	UDR0 ='\n'; */
	}
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
	
	
	//UCSR0B |=(1<<TXCIE0);    //ENABLING TRANSMITTING INTERUPT
	UCSR0B |=(1<<RXCIE0);
	
}
