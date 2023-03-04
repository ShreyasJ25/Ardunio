		// i2c_master 
		//  master master send slave receive 
		
		#include "i2c_master_header.h"
	
	 // normal transmission without repeated START;
		int main(void)
		{
		uint8_t arr[]="data sending but not receiving\n";
		int num =sizeof(arr)/sizeof(uint8_t);
		 data_send(arr,num);

			
		 return 0;
		  }
	
	