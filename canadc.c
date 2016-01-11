#include<LPC17xx.h>
extern void pll();
void canint()
{ 	    LPC_PINCON-> PINSEL0=(1<<2)|(1<<0);   //td1
 //LPC_PINCON-> PINSEL0=(1<<0);  //rd1
	  LPC_SC->PCONP|=(1<<13);  //to  power can1 c
	  pll();
	  LPC_CAN1->MOD=(1<<0);//non-operating
	  LPC_CAN1->BTR=0x0007000E; //	BITRATE100K15MHZ		0x0007000E

	  LPC_CAN1->MOD=(0<<0);		//operating


	  }

void CAN_filter_int()
{
//NVIC_EnableIRQ(25);
// LPC_CAN1->IER= (1<<0);	 //ENABLE CAN RX INTERRUPT
LPC_CANAF->AFMR=1;
LPC_CANAF_RAM->mask[0]=(4<<16)|(5<<0);
LPC_CANAF_RAM->mask[1]=(6<<16)|(7<<0);
LPC_CANAF_RAM->mask[2]=(8<<16)|(9<<0);
LPC_CANAF->SFF_sa=0;
LPC_CANAF->EFF_sa=12;
 LPC_CANAF->EFF_GRP_sa=12;
LPC_CANAF->ENDofTable=12;
LPC_CANAF->AFMR=0;
}

void uart()
{  	pll();
LPC_SC->PCONP|=(1<<3);
LPC_PINCON->PINSEL0|=(1<<4)|(1<<6);


   LPC_UART0->LCR=(3<<0)|(1<<7);
   LPC_UART0->DLL=97;
   LPC_UART0->DLM=0;
   LPC_UART0->LCR &=~(1<<7);
 }

  void tx(char s)
{
	  uart();
while((LPC_UART0->LSR&(1<<5))!=(1<<5));
   LPC_UART0->THR=s;
   
	   
	   }
main()
{ 	
canint();
   NVIC_EnableIRQ(25);
 LPC_CAN1->IER= (1<<0);	 //ENABLE CAN RX INTERRUPT

CAN_filter_int();
	

while(1);
}


void CAN_IRQHandler()
{	
unsigned int a,i;	

	 //tx('p');
a=LPC_CAN1->RDA;
sprintf(s,"%d",a);
  
  for(i=0;s[i]!='\0';i++)
 
tx(s[i]);
//can_tx (5,'a',1,0);	
LPC_CAN1->CMR|=(1<<2);
}