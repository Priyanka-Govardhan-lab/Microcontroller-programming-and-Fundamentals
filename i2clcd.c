 #include<LPC17xx.h>
 #define I  LPC_I2C2
 
 extern void pll();


void cmd(unsigned char a)
  {unsigned char temp;
  	 temp=(a&(0xf0));
   I->I2CONSET=(1<<5)|(1<<6);
  while(I->I2STAT!=0x08);
  I->I2CONCLR=(1<<3)|(1<<5);
   I->I2DAT=0x4e;
while(I->I2STAT!=0x18);
  I->I2CONCLR=(1<<3);
  
  

  I->I2DAT=(temp|0x0c);
  while(I->I2STAT!=(0x28));
  I->I2CONCLR=(1<<3);

  I->I2DAT=(temp|0x0c);
  while(I->I2STAT!=(0x28));
  I->I2CONCLR=(1<<3);

    I->I2DAT=(temp|(0x08)) ;
while(I->I2STAT!=0x28);
I->I2CONCLR=(1<<3);

temp=((a&(0x0f))<<4);
  
  I->I2DAT=(temp|0x0c);
  while(I->I2STAT!=0x28);
  I->I2CONCLR=(1<<3);

   I->I2DAT=(temp|0x0c);
  while(I->I2STAT!=0x28);
  I->I2CONCLR=(1<<3);
 
  I->I2DAT=(temp|(0x08)) ;
while(I->I2STAT!=0x28);
I->I2CONCLR=(1<<3);
I->I2CONSET=(1<<4);
	 I->I2CONCLR=0xff;

 }



 void delay(unsigned int a)
{
int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=2500;j++);
}

 void data(unsigned char a)
  {unsigned char temp;
  	  temp=(a&(0xf0));
  I->I2CONSET=(1<<5)|(1<<6);
  while(I->I2STAT!=0x08);
  I->I2CONCLR=(1<<3)|(1<<5);

  I->I2DAT=0x4e;
  while(I->I2STAT!=0x18);
  I->I2CONCLR=(1<<3);
 
  
  I->I2DAT=(temp|0x0d);
  while(I->I2STAT!=0x28);
  I->I2CONCLR=(1<<3);

   
  I->I2DAT=(temp|0x0d);
  while(I->I2STAT!=0x28);
  I->I2CONCLR=(1<<3);

  
I->I2DAT=(temp|0x09) ;
while(I->I2STAT!=0x28);
I->I2CONCLR=(1<<3);

temp=((a&(0x0f))<<4);

I->I2DAT=(temp|0x0d);
  while(I->I2STAT!=0x28);
  I->I2CONCLR=(1<<3);

   I->I2DAT=(temp|0x0d);
  while(I->I2STAT!=0x28);
  I->I2CONCLR=(1<<3);

 
I->I2DAT=(temp|0x09) ;
while(I->I2STAT!=0x28);
I->I2CONCLR=(1<<3);

 I->I2CONSET=(1<<4);
	 I->I2CONCLR=0xff;


 }

 

main()
{	    
	  unsigned char a[6]="PSR";
   unsigned int i ;
	    pll();

		
  LPC_PINCON->PINSEL0|=(0XA<<20);
   LPC_PINCON->PINMODE0=(0XA<<20);
   LPC_PINCON->PINMODE_OD0=(3<<10);

  	LPC_SC->PCLKSEL1 = (2<<20);
	I->I2SCLL = 150; //300 for 100kbps bitrate
	I->I2SCLH = 150;	
  
  //p->FIODIR=(0x3f<<6)|(0x0f<<15);
  cmd(0x28);
   cmd(0x01);
  cmd(0x0e);
 
  cmd(0x80);
 cmd(0x80);
  //data('f');


  
  for(i=0;a[i]!='\0';i++)
  data(a[i]);
  while(1)
  {cmd(0x1c);
   

  	delay(2050);
  }
     }



