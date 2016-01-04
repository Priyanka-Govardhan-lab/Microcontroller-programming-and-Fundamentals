#include<reg51.h>
void delay();
sfr LED=0x80;

main()
{  
LED=0X00;
  TMOD=0X07;
  TL0=0X00;
   TR0=1;
 while(1)
  { if(TL0==0x0A)
    { 
	LED=0XFF;
	 delay();
	 LED=0X00;
	  delay();
	  
	   
	}
  }
  }
  
  void delay()
{
 unsigned int i;
TMOD=0X03;
 for(i=0;i<3;i++)
 {
 TH0=0x00;
  TR1=1;
 while(TF1==0);
 TF1=0;
 }
 TH0=0x63;
 TR1=1;
 while(TF1==0);
 TF1=0;
 }
 