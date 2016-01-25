	  #include<LPC17xx.h>
	  main()
	  { LPC_PINCON->PINSEL0=(3<<12);
	    LPC_TIM2->PR=14999;
		LPC_TIM2->MR0=1    ;
		LPC_TIM2->MCR=(2<<0);
		LPC_TIM2->EMR=(3<<4);
		LPC_TIM2->TCR=1;
		while(1);
		}