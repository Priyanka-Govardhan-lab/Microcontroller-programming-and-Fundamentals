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
 void can_tx(int id,int data,char dlc,char rtr)
{
while ((LPC_CAN1->SR&(1<<2))==0); // CHECK FOR TX BUFFER STATUS
LPC_CAN1->TID1 = id;	//LOAD ID
LPC_CAN1->TDA1= data; // LOAD DATA TO BE TX
LPC_CAN1->TDB1= 0;
LPC_CAN1->TFI1= (dlc<<16)|(rtr<<30); //LOAD NO. OF DATA BYTES & TYPE OF FRAME
LPC_CAN1->CMR=(1<<0)|(1<<5); // START TX
while ((LPC_CAN1->SR&(1<<3))==0);  // CHECK FOR TX COMPLETION STATUS
LPC_CAN1->CMR=(0<<0); // STOP TX

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
	   {canint();
   NVIC_EnableIRQ(25);
 LPC_CAN1->IER= (1<<0);	 //ENABLE CAN RX INTERRUPT
   


CAN_filter_int();
 can_tx (5,'a',1,0);	

while(1);



}


void CAN_IRQHandler()
{	
unsigned int a;	

	 //tx('p');
a=LPC_CAN1->RDA;
tx(a);

LPC_CAN1->CMR|=(1<<2);

}