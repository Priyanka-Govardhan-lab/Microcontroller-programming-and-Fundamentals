#include<LPC17xx.h>
#define p LPC_GPIO0
#include"pll.c"
void delay(unsigned int x);
main()
{	 unsigned int k;
p->FIODIR=(0x0f<<6);

 while(1)
 {for(k=0;k<50;k++)
 { p->FIOCLR=(0x0f<<6);
     delay(2);
   p->FIOSET=(0x01<<6);
    delay(20);
	p->FIOCLR=(0x01<<6);
	delay(20);
    p->FIOSET=(0x02<<6);
	delay(20);
	p->FIOCLR=(0x02<<6);
	delay(20);
	p->FIOSET=(0x04<<6);
	delay(20);
	p->FIOCLR=(0x04<<6);
	delay(20);
	p->FIOSET=(0x08<<2);
	delay(20);
	p->FIOCLR=(0x08<<2);
	delay(20);
	}
  }
  }
	 void delay(unsigned int x)
	 { 	int i,j;
	 for(i=0;i<x;i++)
	 for(j=0;j<255;j++);
	 }	 

	  