	   #include<reg51.h>
	   
	   sfr LED=0x80;
	   main()
	   { IE=0x81;
	   TMOD=0X01;
	   TL0=0X00;
	   TH0=0X00;
	   TR0=1;
	  while(1);
	   TF0=0;
	   }

	   void time0(void) interrupt 0
	   { LED=~LED;
	   }