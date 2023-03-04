//UART WITHOUT BUFFER
#include "UART_no_buffer.h"
 using namespace std;
 
void fun_send(){
	
	uint8_t arr[7]={'S','H','R','E','Y','A','S'};
		int i=0;
	while(i<7)
	{
		UDR0=arr[i];
		while(!(UCSR0A>>5 & 0x01));
		i++;
	}
	
}


void fun_rec_send() {
	
	uint8_t ab= UDR0;
	while(!(UCSR0A>>5 & 0x01));
	UDR0=ab;

}


int main(void)
{   
	sei();  //enabling global interrupt
	
	initialize();
	attach_int_reciever(&fun_rec_send);
	attach_int_transmitter(&fun_send);
	
	while(1){}
	 return 0;
} 
