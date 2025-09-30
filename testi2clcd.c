#include<lpc17xx.h>
#define I LPC_I2C2

extern void pll();
void  delay(unsigned int a)
{
unsigned int k,j;
for(k=0;k<=a;k++)
for(j=0;j<=255;j++);
}

void uart()
{
LPC_PINCON->PINSEL0|=(1<<4)|(1<<6);
LPC_UART0->LCR=(1<<7)|(3<<0);
LPC_UART0->DLL=97;
LPC_UART0->DLM=0;
LPC_UART0->LCR&=~(1<<7);

 }
 void tx(unsigned char a)
 {
 while((LPC_UART0->LSR&(1<<5))!=(1<<5));
LPC_UART0->THR=a;
}


void lcdcmd(unsigned char cmd)
{
	unsigned char temp;
	temp = (cmd & (0xf0));	 			//unmasking msb
	
	I->I2CONSET = (1<<6) |(1<<5);
	while((I->I2STAT)!= (0X08));
	I->I2CONCLR = (1<<3) |(1<<5);
	
	I->I2DAT = 0X4E;					// slave addr of lcd
	
	while((I->I2STAT)!= (0X18));
	I->I2CONCLR = (1<<3);
	
//	I->I2DAT = (temp | (0x0c));			//enable =1
//
//	while((I->I2STAT)!= (0X28));
//	I->I2CONCLR = (1<<3);
//		
	I->I2DAT = (temp | (0x0c));			//enable =1	again to avoid delay

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
		
		I->I2DAT = (temp | (0x0c));			//enable =1

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
		
	I->I2DAT = (temp | (0x08));			//enable =0

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
		
	

	temp = ((cmd & (0x0f))<<4);	
	I->I2DAT = (temp | (0x0C));	 			//unmasking lsb
	
	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
		
//	I->I2DAT = (temp | (0x0c));			//enable =1
//
//	while((I->I2STAT)!= (0X28));
//	I->I2CONCLR = (1<<3);
		
		I->I2DAT = (temp | (0x0c));			//enable =1

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
	
	
	I->I2DAT = (temp | (0x08));			//enable =0

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
		
	I->I2CONSET=(1<<4);
	I->I2CONCLR = (0xff);
}

void lcddata(unsigned char data)
{
	unsigned char var;
	var = (data & (0xf0));	 			//unmasking msb
	
	I->I2CONSET = (1<<6) |(1<<5);
	while((I->I2STAT)!= (0X08));
	I->I2CONCLR = (1<<3) |(1<<5);
	   
	I->I2DAT = 0X4E;					// slave addr of lcd
	
	while((I->I2STAT)!= (0X18));
	I->I2CONCLR = (1<<3);
	
	
	I->I2DAT = (var | (0x0d));			//enable =1

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
	
	I->I2DAT = (var | (0x0d));			//enable =1	again to avoid delay

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
	
	
//	I->I2DAT = (var | (0x0d));			//enable =1
//
//	while((I->I2STAT)!= (0X28));
//	I->I2CONCLR = (1<<3);
//	
	I->I2DAT = (var | (0x09));			//enable =0

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
	
		  

	var = ((data & (0x0f))<<4);	
	I->I2DAT = (var | (0x0d));			
	
	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
	

	I->I2DAT = (var | (0x0d));			//enable =1

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);

//	I->I2DAT = (var | (0x0d));			//enable =1
//
//	while((I->I2STAT)!= (0X28));
// I->I2CONCLR = (1<<3);
//						 tx('i');

	I->I2DAT = (var | (0x09));			//enable =0

	while((I->I2STAT)!= (0X28));
	I->I2CONCLR = (1<<3);
		 tx('p');
	
	I->I2CONSET=(1<<4);

	I->I2CONCLR = (0xff);
}

void i2c()
{
	LPC_PINCON->PINSEL0 |= (2<<20) | (2<<22);  //P0.10 , P0.11 are SDA,SCL
	LPC_PINCON->PINMODE0 =(2<<20) |(2<<22);
	LPC_PINCON->PINMODE_OD0 = (3<<10);
	LPC_SC->PCLKSEL1 = (2<<20);
	I->I2SCLL = 150; //300 for 100kbps bitrate
	I->I2SCLH = 150;
}


int main()
{
unsigned char n[15]="karan";
unsigned char q[30]="code working perfectly";
unsigned int i,d;

	pll();
	uart();
	i2c(); 

	
			
	lcdcmd(0x28);		
	lcdcmd(0x0e);
	lcdcmd(0x01);	
	lcdcmd(0x80);
	lcdcmd(0x80);
	for(i=0;n[i]!='\0';i++)
	{
	lcddata(n[i]);

	 }
	 
	 //delay(100);
	 lcdcmd(0xc0);
	 for(d=0;q[d]!='\0';d++)
	 {
	 lcddata(q[d]);
    }
	   while(1);
	   
}
