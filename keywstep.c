#include<reg51.h>

void delay (unsigned int a);
void anticlock (unsigned int b);
void clock (unsigned int b);
int main()

{
	unsigned int step=50;
	char var;
		P2=0x0f;
	while(1)
	{
		P2=0xef;
		var=P2;
		switch (var)
		{
			case 0xe7 : clock(step);
						break;
			case 0xeb :  anticlock(step);
						break;
		}
	}
}

void anticlock (unsigned int b)

{	  unsigned int i;
	
	for(i=0; i<b; i++)
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

}


void clock (unsigned int b)

{
		 unsigned int i;
	for(i=0; i<b; i++)
	{
		P0=0x80;
		delay (10);
        P0=0x40;
		delay (10);
		P0=0x20;
		delay (10);
		P0=0x01;
		delay (10);
	}
	
}
