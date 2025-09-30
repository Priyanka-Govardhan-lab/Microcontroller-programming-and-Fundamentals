#include<lpc17xx.h>
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
 void CAN_tx(int data,int id,int rtr,int dlc)

{while((LPC_CAN1->SR&(1<<2))!=(1<<2));
		  LPC_CAN1->TDA1=data;   //data
		  LPC_CAN1->TDB1=0;
		   LPC_CAN1->TID1=id;	  //id
		   LPC_CAN1->TFI1=(dlc<<16)|(rtr<<30); 	   //rtr=0,dlc=length of data
		   LPC_CAN1->CMR=(1<<0)|(1<<5);
		 while((LPC_CAN1->SR&(1<<3))!=(1<<3));
		 LPC_CAN1->CMR=(0<<0); 
	  }

	  main()
	  { canint();
	  	
		CAN_tx('R',4,0,1);
	//	tx('s');
	
		 }