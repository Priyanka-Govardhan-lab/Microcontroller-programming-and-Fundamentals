//single switch single led
#include<LPC17xx.h>
#define p LPC_GPIO1
#define r LPC_GPIO2
main()
{
p->FIODIR=(1<<29);
r->FIODIR=(0<<10);

while(1)
{
 if((r->FIOPIN&(1<<10))==(1<<10))

  p->FIOCLR=(1<<29);
  else
  p->FIOSET=(1<<29);
 }
}