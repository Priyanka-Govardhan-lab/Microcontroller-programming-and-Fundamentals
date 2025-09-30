#include<LPC17xx.h>
#define p LPC_GPIO0
void delay(unsigned int x);
 void lcddata(unsigned char b) ;
 void lcdcmd(unsigned char a);
main()
{ 	
   unsigned char a[14]="happy dussera";
   unsigned int i ;
  p->FIODIR=(0x3f<<6)|(0x0f<<15);
  lcdcmd(0x28);
  lcdcmd(0x0e);
  lcdcmd(0x01);
  lcdcmd(0x80);
  for(i=0;a[i]!='\0';i++)
  lcddata(a[i]);
  while(1)
  {lcdcmd(0x10);
  delay(10);
  }
  }

  void lcdcmd(unsigned char a)
	{ 
	unsigned char temp;
	p->FIOCLR=(1<<11);
	temp=(a&0xf0)>>4;

	
	p->FIOCLR=(0xf<<6);
	p->FIOSET=(temp<<6);
	p->FIOSET=(1<<10);	
	delay(1000);
	
	p->FIOCLR=(1<<10);
	temp=a&(0x0f);
	p->FIOCLR=(0xf<<6);
	p->FIOSET=(temp<<6);
	
	p->FIOSET=(1<<10);
		
	delay(100);
	p->FIOCLR=(1<<10);
	
	}
	void lcddata(unsigned char b)
	{ 
	unsigned char temp;
	p->FIOSET=(1<<11);
	temp=(b&0xf0)>>4;
    p->FIOCLR=(0xf<<6);
	p->FIOSET=(temp<<6);
	p->FIOSET=(1<<10);	
	delay(100);
    p->FIOCLR=(1<<10);
	temp=b&(0x0f);
	p->FIOCLR=(0xf<<6);
	p->FIOSET=(temp<<6);
	p->FIOSET=(1<<10);
    delay(100);
	p->FIOCLR=(1<<10);
	
	}


   void delay(unsigned int x)
	 { 	int i,j;
	 for(i=0;i<x;i++)
	 for(j=0;j<255;j++);
	 }	 



