		 #include<lpc17xx.h>
		 #include"pll.c"
		 #define t0 LPC_TIM0
		 int main()
		 { LPC_GPIO1->FIODIR=(1<<29);
		
		 pll();
		 t0->PR=14999;
		 t0->MR0=1000;
		 t0->MCR=(7<<0);
		 t0->TCR=(1<<0);
		 NVIC_EnableIRQ(1);
		 while(1);
		 }
		 
		 void TIMER0_IRQHandler()
		 { int i;//LPC_GPIO1->FIOSET=(1<<29);
		// LPC_GPIO1->FIOSET=(1<<29);
		 
		LPC_GPIO1-> FIOPIN ^=(1<<29);
		 t0->IR=(1<<0);	 
		t0->TC=0;
		 t0->TCR=(1<<0);
		 t0->IR=(1<<0);
	   
		
		 }