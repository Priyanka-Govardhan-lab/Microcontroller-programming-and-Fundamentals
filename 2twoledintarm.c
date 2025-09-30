		   #include<lpc17xx.h>
		 #include"pll.c"
		 #define t0 LPC_TIM0
		 int main()
		 { LPC_GPIO0->FIODIR=(1<<6)|(1<<7);
		 //LPC_GPIO1->FIODIR=(1<<28) ;

		
		 pll();
		 t0->PR=14999;
		 t0->MR0=1000;
		 t0->MR1=5000;
		 t0->MCR=(1<<0)|(3<<3);
		 t0->TCR=(1<<0);
		 NVIC_EnableIRQ(1);
		 while(1)
		 { // LPC_GPIO0-> FIOCLR =(1<<6);
		 //LPC_GPIO0-> FIOCLR =(1<<7);
		 }
		 }
		 
		 void TIMER0_IRQHandler()
		 { 
		 int i;//LPC_GPIO1->FIOSET=(1<<29);
		// LPC_GPIO1->FIOSET=(1<<29);
		 
		if(((t0->IR)&(1<<0))==(1<<0))
		{
		LPC_GPIO0-> FIOSET =(1<<6);
		 LPC_GPIO0-> FIOCLR =(1<<7);
		 t0->IR=(1<<0);
		 }
		else if(((t0->IR)&(1<<1))==(1<<1))
		{
		 LPC_GPIO0-> FIOSET =(1<<7);
		LPC_GPIO0-> FIOCLR =(1<<6);
	    t0->IR=(1<<1);
		}
		 	 
		//t0->TC=0;
		 //t0->TCR=(1<<0);
		 //t0->IR=(1<<0);
	   
		
		 }