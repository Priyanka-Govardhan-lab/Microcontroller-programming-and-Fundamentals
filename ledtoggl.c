	#include<LPC17xx.h>





	  void main()

	  {
	 
	    LPC_PINCON->PINSEL0=(0xff<<12);  
	    
	    LPC_TIM2->PR=14999;
		LPC_TIM2->MR0=1;
		LPC_TIM2->MR1=3;
		LPC_TIM2->MR2=6;
		LPC_TIM2->MR3=10;
        LPC_TIM2->MCR=(1<<10);
		LPC_TIM2->EMR=(3<<4)|(3<<6)|(3<<8)|(3<<10);
		LPC_TIM2->TCR=1;
		while(1);
		}