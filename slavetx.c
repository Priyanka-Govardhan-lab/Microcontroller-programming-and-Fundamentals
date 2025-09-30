#include<LPC17xx.h>
  extern void pll();
  #define I LPC_I2C2


void uart()
{  	pll();
LPC_SC->PCONP|=(1<<3);
LPC_PINCON->PINSEL0|=(1<<4)|(1<<6);


   LPC_UART0->LCR=(3<<0)|(1<<7);
   LPC_UART0->DLL=97;
   LPC_UART0->DLM=0;
   LPC_UART0->LCR &=~(1<<7);
 }

  void tr(char s)
{

while((LPC_UART0->LSR&(1<<5))!=(1<<5));
   LPC_UART0->THR=s;
   
	   
	   }

  main()
   {
   pll();
   
 
 
   //LPC_SC->PCONP|=(1<<26);
   LPC_PINCON->PINSEL0|=(0XA<<20);
   LPC_PINCON->PINMODE0=(0XA<<20);
   LPC_PINCON->PINMODE_OD0=(3<<10);
   //LPC_SC->PCLKSEL1=(1<<21);
   I->I2SCLL=75;
   I->I2SCLH=75;
      
   I->I2CONSET=(1<<6)|(1<<2);
   I->I2ADR0=0xf0;
   while(I->I2STAT!=(0Xa8));
   I->I2CONCLR=(1<<3);
   	I->I2DAT='a';
 
  while(I->I2STAT!=0Xb8);
  I->I2CONCLR=(1<<3);
  
//  I->I2DAT='g';
//  while(I->I2STAT!=(0Xc0));
//  I->I2CONCLR=(1<<3);
//   //tr('y'); 
//  I->I2CONSET=(1<<4);
  I->I2CONCLR=0XFF;
  // tr('z'); 
  while(1);
 } 