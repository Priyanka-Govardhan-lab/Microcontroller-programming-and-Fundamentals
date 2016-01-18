#include<reg51.h>
sfr LED=0x80;
void delay();
int main()
{  TMOD=0x01;
while(1)
{LED =0xff;
delay();
LED=0x00;
delay(); }
}

void delay()
{ unsigned int i;
 for(i=0;i<14;i++)
 { //TMOD=0x01;
 TH0=0x00;
 TL0=0x00;
 TR0=1;
 while(TF0==0);
 TF0=0;
 TL0=0xc6;
 TH0=0xef;
 TR0=1;
 while(TF0==0);
 TF0=0;
 }
 	   }