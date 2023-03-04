 #include "i2c_slave_header.h"
 
 #define F_CPU 16000000
 #define BAUD 9600
 #define N 100
 #include <util/setbaud.h>
 
 #include <util/delay.h>
 #define NULL 0
 #include <avr/io.h>
  #include <avr/interrupt.h>

 
 uint8_t rec_arr[N];
 uint16_t ri=0,rj=0;
 uint8_t status;
 volatile uint8_t* i2c_receive();
 void i2c_init(){
	 
	 TWAR =(8<<1); //initialized with slave address
	 TWCR|=(1<<TWEA)|(1<<TWEN)|(1<<TWIE); //interrupt enable
	 PORTD |=(1<<PD0);
	 PORTD |=(1<<PD1); //pulling up sda and scl ;make port value 1 and direction bit 0
	 DDRD &=~(1<<PD0);
	 DDRD &=~(1<<PD1);
	 
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



ISR(TWI_vect){
	volatile uint8_t *temp = i2c_receive();
	if(temp != NULL)
	{
		rec_arr[rj++] =(uint8_t) *temp;
		rj = rj%N;
		if(ri==rj){
			ri++;
			ri=ri%N;
			
		}
	}
	TWCR |=(1<<TWINT); //as interrupt is handled by the ISR the TWINT should be cleared by software
	//read_buff();
}

void read_buff(){
	if(ri!=rj){
		
		UDR0 = (char) rec_arr[ri];   //data
		while(!(UCSR0A>>5 & 0X01));
		ri++;
		ri=ri%N;
	}
}


volatile uint8_t* i2c_receive() {
	status = TWSR & 0xf8;
	//Serial.println(status, HEX);
	if (status == 0x80 || status == 0x90) {
		//refer the data sheet for the status
		return (&TWDR);
	}
	else if (status == 0x88 || status == 0x98) {
		return (&TWDR);
	}
	
	else return (volatile uint8_t)NULL;
}

void initialize_spi_slave(){
	sei();
	i2c_init();
	initialize_uart();
} 