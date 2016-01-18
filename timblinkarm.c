#include<LPC17xx.h>
#define p LPC_GPIO0
#include"pll.c"
void delay();
main()
{	
pll();
p->FIODIR=(1<<0);
 
  while(1)
  {

p->FIOSET=1;
    delay();
	p->FIOCLR=1;
 delay();
} }


void delay()
{ 
 LPC_TIM0->PR=(14999);
LPC_TIM0->MR0=(1000);
LPC_TIM0->MCR=(7);
LPC_TIM0->TCR=(1);
while((LPC_TIM0->IR&(1<<0))!=(1<<0));
LPC_TIM0->IR=(1<<0);

}