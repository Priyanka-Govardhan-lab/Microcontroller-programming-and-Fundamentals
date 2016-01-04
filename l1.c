          #include<reg51.h>
			  sfr LED =0x80;
			  int i;
			  void delay(unsigned int a);
			  int main()
			  { p =0X01;
			  for(i=0;i<6;i++)
			    {
			
				
				LED=p<<i;
				delay(100);
				}}

				void delay(unsigned int a)
				{ unsigned int i,j;
				for(i=0;i<a;i++)
				for(j=0;j<=255;j++);
				}