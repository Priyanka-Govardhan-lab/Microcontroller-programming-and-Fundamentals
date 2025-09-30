	  #include<reg51.h>
			  sfr LED =0x80;
			  int p;
			  void delay(unsigned int a);
			  int main()
			  {
			 
			  p =0X01;
			
			  	 
	       
			    do
				{
			      LED=p++;
				delay(200);
				}while(LED<0x08);
			
				}
			
			   
				void delay(unsigned int a)
				{ unsigned int i,j;
				for(i=0;i<a;i++)
				for(j=0;j<=255;j++);
				}
				