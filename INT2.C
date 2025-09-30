#include<reg51.h>
main()
{ IE=0x90;
   TMOD=0X20;
   SCON=0X50;
           TH1=0XFD;
        TR1=1;
	SBUF='a';
		while(TI==0);
		TI=0;
       while(1);
	   
   
}

	   
	   void ser0(void) interrupt 4
	   {   	 unsigned char a;
	     SBUF='P';
		 while(TI==0);
		  //a=SBUF ;
		  //SBUF=a;
		  TI=0;
		  
	   }