#include<reg51.h>
void delay (unsigned int a);
int main()

{
	unsigned int i;
	for(i=0; i<50; i++)
	{
		P0=0x01;
		delay (10);
        P0=0x02;
		delay (10);
		P0=0x04;
		delay (10);
		P0=0x08;
		delay (10);
	}
	return 0;
}

void delay (unsigned int a)
                 {
                	unsigned int i,j;
 					for(i=0;i<=a;i++)
					  {
						for(j=0;j<255;j++);
					   }
				}