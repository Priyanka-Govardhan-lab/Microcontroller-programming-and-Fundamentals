		 #include<lpc17xx.h>

		//char str[]="Megha";
				
		 void delay(unsigned int value)
		 {
		   int i,j;
		   for(i=0;i<value;i++)
		   {
		   
		   for(j=0;j<1250;j++)
		   {}}
		  }

		void lcd_cmd(unsigned char a)
		{
					unsigned char b;
					LPC_GPIO0->FIOCLR=(1<<10);

					b=a&0xf0; b=(b>>4);

					LPC_GPIO0->FIOCLR=(0x0F<<6);
					LPC_GPIO0->FIOSET=(b<<6);

					LPC_GPIO0->FIOSET=(1<<11);
					 delay(200);
					LPC_GPIO0->FIOCLR=(1<<11);
					 delay(200);

				 		b=a&0x0f; 

					LPC_GPIO0->FIOCLR=(0x0F<<6);
					LPC_GPIO0->FIOSET=(b<<6);

					LPC_GPIO0->FIOSET=(1<<11);
					 delay(200);
					LPC_GPIO0->FIOCLR=(1<<11);
					 delay(200);
		  }

		  	void lcd_data(unsigned char a)
		{
					unsigned char b;
					LPC_GPIO0->FIOSET=(1<<10);

					b=a&0xf0; b=(b>>4);

					LPC_GPIO0->FIOCLR=(0x0F<<6);
					LPC_GPIO0->FIOSET=(b<<6);

					LPC_GPIO0->FIOSET=(1<<11);
					 delay(200);
					LPC_GPIO0->FIOCLR=(1<<11);
					 delay(200);

				 		b=a&0x0f; 

					LPC_GPIO0->FIOCLR=(0x0F<<6);
					LPC_GPIO0->FIOSET=(b<<6);

					LPC_GPIO0->FIOSET=(1<<11);
					 delay(200);
					LPC_GPIO0->FIOCLR=(1<<11);
					 delay(200);
		  }

		  int main()

		{                              
			
				 unsigned char a;
LPC_GPIO0->FIODIR=(0x3F<<6)|(0xF0<<15);
				lcd_cmd(0x28);	  
				lcd_cmd(0x01);	 
				lcd_cmd(0x0E);
				lcd_cmd(0x80);

				lcd_data('X');
				
				

				while(1) 
				{
				LPC_GPIO0->FIOPIN=(0xEF<<15);
				  a=(LPC_GPIO0->FIOPIN&(0xFF<<15))>>15;

	switch(a)
{
	case 0xE7: lcd_data('0');break;
	case 0xEB: lcd_data('1');break;
	case 0xED: lcd_data('2');break;
	case 0xEE: lcd_data('3');break;
}
				LPC_GPIO0->FIOPIN=(0xDF<<15);
				  a=(LPC_GPIO0->FIOPIN&(0xFF<<15))>>15;
	switch(a)
{
	case 0xD7: lcd_data('4');break;
	case 0xDB: lcd_data('5');break;
	case 0xDD: lcd_data('6');break;
	case 0xDE: lcd_data('7');break;
 }
 				
				LPC_GPIO0->FIOPIN=(0xBF<<15);
				  a=(LPC_GPIO0->FIOPIN&(0xFF<<15))>>15;
	switch(a)

  {
	case 0xB7: lcd_data('8');break;
	case 0xBB: lcd_data('9');break;
	case 0xBD: lcd_data('A');break;
	case 0xBE: lcd_data('B');break;
   }

				LPC_GPIO0->FIOPIN=(0x7F<<15);
				  a=(LPC_GPIO0->FIOPIN&(0xFF<<15))>>15;
	 switch(a)
   {
	case 0x77: lcd_data('C');break;
	case 0x7B: lcd_data('D');break;
	case 0x7D: lcd_data('E');break;
	case 0x7E: lcd_data('F');break;
	}
}
}
				  		  	
			


		/* for(i=0;str[i]!='\0';i++)
		   {
			lcd_data(str[i]);
		} */
							   	
								




