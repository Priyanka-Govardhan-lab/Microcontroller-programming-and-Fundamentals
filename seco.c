			  #include<reg51.h>
			  sfr LED =0x80;
			  void delay(unsigned int a);
			  int main()
			  { while(1)
			    {LED =0xff;
				delay(100);
				LED=0x0000000;
				delay(100);
				}}

				void delay(unsigned int a)
				{ unsigned int i,j;
				for(i=0;i<a;i++)
				for(j=0;j<=255;j++);
				}