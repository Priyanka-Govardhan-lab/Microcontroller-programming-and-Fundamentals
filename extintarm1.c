#include<lpc17xx.h>
main()
{ LPC_PINCON->PINSEL4=(1<<20);
  LPC_SC->EXTMODE=(1<<0);
  LPC_SC->EXTPOLAR=(1<<0);
LPC_GPIO1->FIODIR=(1<<29);
NVIC_EnableIRQ(18);
while(1)
{ LPC_GPIO1->FIOCLR=(1<<29);
}}
void EINT0_IRQHandler()
{LPC_GPIO1->FIOSET=(1<<29);
LPC_SC->EXTINT=(1<<0);
//LPC_SC->EXTMODE=(1<<0);
//LPC_SC->EXTPOLAR=(1<<0);
}