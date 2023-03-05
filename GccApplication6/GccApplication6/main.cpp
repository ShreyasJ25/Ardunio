
//ADC

#include <avr/io.h>

#include "source_header.h"
using namespace std;

// task is a user defined function that converts the adc 10bit values to stream of uint8_t values to send it to serial monitor

void task(){
	
	cli();  //disabling the interrupt
	int num =ADC;
	int num1=num,num2=0;
	char arr[4];
	for(int j=0;j<4;j++){
		num1=num/10;
		num2 =num - num1*10;
		arr[j] = num2 + '0';
		num =num1;
}

	for(int j=3;j>=0;j--){
				while(!(UCSR0A>>5 & 0x01));
				UDR0 =arr[j];
	}
	while(!(UCSR0A>>5 & 0x01));
	UDR0 ='\n';
	
	sei();  //enabling interrupt only after conversion
}
	



int main(void)
{
	sei();
	initialize_uart();
	initialize_adc();
	attach_adc_interrupt(&task);
	enable_adc_convertion();
     
	 
	 
	//task();
   
    while (1) 
    {
		
		
    }
	return 0;
}


//using interrupts


