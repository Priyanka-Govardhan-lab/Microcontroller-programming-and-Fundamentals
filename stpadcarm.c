#include<LPC17xx.h>
#define p LPC_GPIO0
#include"pll.c"
unsigned int x;
 void delay(unsigned int x);
 char a[30]="rotating";
 char b[30]="not-rotationg";
void stp()
{ unsigned int k;
  p->FIODIR=(0x0f<<15);

 while(1)
 {
 
      p->FIOCLR=(0x0f<<15);
     delay(2);
   p->FIOSET=(0x01<<15);
    delay(20);
	p->FIOCLR=(0x01<<15);
	delay(20);
    p->FIOSET=(0x02<<15);
	delay(20);
	p->FIOCLR=(0x02<<15);
	delay(20);
	p->FIOSET=(0x04<<15);
	delay(20);
	p->FIOCLR=(0x04<< 15); 
	
  }
  }
	 void delay(unsigned int x)
	 { 	int i,j;
	 for(i=0;i<x;i++)
	 for(j=0;j<255;j++);
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
	 
	 
	 
	 main()
{ 
unsigned int i;
  char s[12];
  LPC_GPIO0->FIODIR = (0x3f<<6);
  LPC_PINCON-> PINSEL1=(1<<14);
  LPC_SC->PCONP|=(1<<12);
  pll();
  lcdcmd(0x28);
lcdcmd(0X0e);
lcdcmd(0X01);
lcdcmd(0x80);
lcddata('A');
  LPC_ADC->ADCR=(1<<0)|(14<<8)|(1<<21)|(1<<24);
  while((LPC_ADC->ADDR0&(1<<31))!=(1<<31)) ;
  x=LPC_ADC->ADDR0;
  x=(x&(0xfff<<4))>>4;
  if(x>1000)
  {lcdcmd(0x28);
lcdcmd(0X0e);
lcdcmd(0X01);
lcdcmd(0x80);
  for(i=0;a[i]!='\0';i++)
  lcddata(a[i]);
  stp();
  }
  else if(x<1000)
  {lcdcmd(0x28);
lcdcmd(0X0e);
lcdcmd(0X01);
lcdcmd(0x80);
  for(i=0;b[i]!='\0';i++)
  lcddata(b[i]);
  }
  sprintf(s,"%d",x);
  for(i=0;s[i]!='\0';i++)
  lcddata(s[i]);
  while(1);
  } 