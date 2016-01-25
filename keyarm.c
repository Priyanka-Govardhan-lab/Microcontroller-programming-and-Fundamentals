//keyboard																											  #include<reg51.h>

#include<LPC17xx.h>
#define p LPC_GPIO0
void delay(unsigned int x);
 void lcddata(unsigned char b) ;
 void lcdcmd(unsigned char a);
 
main()
{ 	
   unsigned int a;
  p->FIODIR=(0x3f<<6)|(0x0f<<15);
  lcdcmd(0x28);
  lcdcmd(0x0e);
  lcdcmd(0x01);
  lcdcmd(0x80);
  lcddata('a');
  while(1) 
  { p->FIOPIN=(0xf7<<15);
    a=(p->FIOPIN&(0xff<<15))>>15;
  switch(a)
 
  {  case 0xe7:lcddata('0');break;
    case 0xd7:lcddata('1');break;
	case 0xb7:lcddata('2');break;
	case 0x77:lcddata('3');break;
	}

	p->FIOPIN=(0xfb<<15);
 
  switch(a)
  { case 0xeb:lcddata('4');break;
    case 0xdb:lcddata('5');break;
	case 0xbb:lcddata('6');break;
	case 0x7b:lcddata('7');break;
	}

	p->FIOPIN=(0xfd<<15);
    a=(p->FIOPIN&(0xff<<15))>>15;
  switch(a)
  { case 0xed:lcddata('8');break;
    case 0xdd:lcddata('9');break;
	case 0xbd:lcddata('A');break;
	case 0x7d:lcddata('B');break;
	}

	p->FIOPIN=(0xfe<<15);
    a=(p->FIOPIN&(0xff<<15))>>15;
  switch(a)
  { case 0xee:lcddata('c');break;
    case 0xde:lcddata('D');break;
	case 0xbe:lcddata('E');break;
	case 0x7e:lcddata('F');break;
	}
	delay(1000);
	}}
	
	void lcdcmd(unsigned char a)
	{ 
	unsigned char temp;
	p->FIOCLR=(1<<11)
	
	;
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



