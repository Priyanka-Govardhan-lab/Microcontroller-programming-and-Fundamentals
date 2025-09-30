									      #include<lpc17xx.h>
#include"pll.c"
unsigned char s[10]="piysa";
char x,i;
int main()
{
LPC_PINCON->PINSEL0=(1<<4)|(1<<6);
  pll();
   LPC_UART0->LCR=(3<<0)|(1<<7);
   LPC_UART0->DLL=97;
   LPC_UART0->DLM=0;
   LPC_UART0->LCR &=~(1<<7);

   for(i=0;s[i]!='\0';i++)
   {
      while((LPC_UART0->LSR&(1<<5))!=(1<<5));
   LPC_UART0->THR=s[i];
   }
	   while(1);
	   }