#include "i2c_master_header.h"

#define  F_CPU 16000000
		#define SCL_CLK 1000000
		#include <avr/io.h>
		#include <util/delay.h>
		#include <string.h>


		

		void i2c_init(){
			TWBR |=(1<<2); //value is 4;//this is bit rate register
			TWSR &=~(1<<1);
			TWSR &=~(1<<0); //setting pre-scaler value to 00 i.e 1  //here  0.66Mhz
			 /*
			 SCL_freq = cpu_freq/(16 +2(TWBR)*(pow(4,TWPS)))
			 */
			}

	

		uint8_t i2c_start(uint8_t address){
			
			TWCR |=(1<<TWINT)|(1<<TWSTA)|(1<< TWEN); //ENABLING START CONDITION
			uint8_t status = 0;
			while(!(TWCR&(1<<TWINT))); //wait for TWINT to set
			status =TWSR & 0xf8;
			// Serial.print("status 1:");
			// Serial.println(status,HEX);
			if(status != 0x08)return 0;
			TWDR = (address<<1);
			TWCR |=(1<<TWINT)|(1<<TWEN); //address can only be written when TWINT is 1
			TWCR &=~(1<<TWSTA);  // we are stopping start bit otherwise repeated start would be called
			while(!(TWCR&(1<<TWINT))); //wait for TWINT to set
			status =TWSR & 0xf8;
			// Serial.print("status 2:");
			// Serial.println(status,HEX);
			if(status==0x18)return 1; //SLA+W has been transmitted, ACK has been received
			else if(status ==0x20)return 2; //SLA +W has been transmitted , ACK not received
			else return 3 ; //arbitration lost in SLA+W or data bytes
			
		}
		uint8_t i2c_write (uint8_t data){
			
			uint8_t status;
			TWDR = data;
			TWCR |=(1<<TWINT)|(1<<TWEN); //address can only be written when TWINT is 1
			
			while(!(TWCR&(1<<TWINT))); //wait for TWINT to set
			status =TWSR & 0xf8;
			// Serial.print("status 3:");
			//Serial.println(status,HEX);
			if(status == 0x28)return 1; // data has been transmitted and ACK is received
			else if(status ==0x30)return 2; //data transmitted but ACK not received
			else return 3; //arbitration lost in SLA+W or data bytes
			
		}
		void i2c_stop(){
			
			TWCR |=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
			while(!(TWCR &(1<<TWSTO)));
		}

void data_send(uint8_t arr[],int num){
	//uint8_t arr[]=ar;
	//int num = sizeof(arr)/sizeof(arr[0]) -1;
	i2c_init();
	uint8_t status;
	while (1){
		status= i2c_start((uint8_t)(8));
		if(status ==1){
			for(int i=0;i<(num);i++){
				status = i2c_write(arr[i]);
}
	}
		i2c_stop();
		_delay_ms(2000);
	}
}
