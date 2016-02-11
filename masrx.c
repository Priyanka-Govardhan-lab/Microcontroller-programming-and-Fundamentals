#include<LPC17xx.h>
  extern void pll();
  #define I LPC_I2C2
  char a;
  void tr(char );
void uart()
{  	pll();
LPC_SC->PCONP|=(1<<3);
LPC_PINCON->PINSEL0|=(1<<4)|(1<<6);


   LPC_UART0->LCR=(3<<0)|(1<<7);
   LPC_UART0->DLL=97;
   LPC_UART0->DLM=0;
   LPC_UART0->LCR &=~(1<<7);
 }


  main()
   {  
   
   pll();
   uart();

   //LPC_SC->PCONP|=(1<<26);
   LPC_PINCON->PINSEL0|=(0X0A<<20);
   LPC_PINCON->PINMODE0=(0X0A<<20);
   LPC_PINCON->PINMODE_OD0=(3<<10);
   //LPC_SC->PCLKSEL1=(1<<21);
   I->I2SCLL=75;		  //150
   I->I2SCLH=75;		   //150
   I->I2CONSET=(1<<6)|(1<<5);
   
  
   while(I->I2STAT!=0X08);
	 
   I->I2CONCLR=(1<<3)|(1<<5);
   I->I2DAT=(0xf1);


   while(I->I2STAT!=0X40);
   I->I2CONCLR=(1<<3);
   LPC_I2C2->I2CONSET=(1<<2);
while (LPC_I2C2->I2STAT!=0X50);
LPC_I2C2->I2CONCLR=(1<<3);
  a=I->I2DAT;
  tr(a);
  LPC_I2C2->I2CONSET=(1<<4); // send stop bit
LPC_I2C2->I2CONCLR=0xff;
 
 } 



  void tr(char s)
{

while((LPC_UART0->LSR&(1<<5))!=(1<<5));
   LPC_UART0->THR=s;
   
	   
	   }