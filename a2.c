#include<LPC17xx.h>
#define p LPC_GPIO0
void delay(unsigned int x);
main()
{
p->FIODIR=(0x0f<<2);

 while(1)
 { p->FIOCLR=(0x0f<<2);
 delay(500);
 p->FIOSET=(0x08<<2);
    delay(500);
	p->FIOCLR=(0x08<<2);
	delay(500);
    p->FIOSET=(0x04<<2);
	delay(500);
	p->FIOCLR=(0x04<<2);
	delay(500);
	p->FIOSET=(0x02<<2);
	delay(500);
	p->FIOCLR=(0x02<<2);
	delay(500);
	p->FIOSET=(0x01<<2);
	delay(500);
	p->FIOCLR=(0x01<<2);
	delay(500);

  }
  }
	 void delay(unsigned int x)
	 { 	int i,j;
	 for(i=0;i<x;i++)
	 for(j=0;j<255;j++);
	 }	 