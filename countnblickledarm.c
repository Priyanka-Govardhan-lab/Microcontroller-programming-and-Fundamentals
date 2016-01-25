 #include<LPC17xx.h>
 #include"pll.c"
 main()
 {   
 
     LPC_GPIO1->FIODIR=(1<<29)  ;
	LPC_SC->PCONP|=(1<<23) ;
	  LPC_PINCON->PINSEL1=(3<<14);//p0.23  as cap3.0
	  pll();
	  LPC_TIM3->PR=0;
	  LPC_TIM3->MR0=10;
	  LPC_TIM3->MCR=(7<<0);
	  LPC_TIM3->CTCR=(3<<0);
	  LPC_TIM3->TCR=(1<<0);
	  while(((LPC_TIM3->IR)&(1<<0))!=(1<<0));
	  LPC_TIM3->IR=(1<<0);
	  LPC_GPIO1->FIOSET=(1<<29);
	  while(1);
	  }
