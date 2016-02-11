#include<lpc17xx.h>
void pll()
{
  LPC_SC->SCS = (1<<5);

  while((LPC_SC->SCS&(1<<6))!=(1<<6));
LPC_SC->CLKSRCSEL=(1<<0);
   LPC_SC->PLL0CON =(1<<0);
  
   LPC_SC->PLL0CFG  = (14<<0)|(0<<16);
   
   LPC_SC->PLL0FEED = 0xaa;
   LPC_SC->PLL0FEED = 0x55;
   while((LPC_SC->PLL0STAT&(1<<26))!=(1<<26));
   LPC_SC->CCLKCFG=0x05;
  LPC_SC->PLL0CON=(1<<1)|(1<<0);
   LPC_SC->PLL0FEED = 0xaa;
   LPC_SC->PLL0FEED = 0x55; 
  

}
