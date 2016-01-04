#include<reg51.h>
sfr LED =0x80;
void delay30();
void delay20();

main()
{ TMOD=0x01;
 while(1)
 { LED=0xff;
   delay30();
   LED=0x00;
    delay20();
	}
 }

 void delay30()
 { TH0=0x93;
   TL0=0xfd;
   TR0=1;
   while(TF0==0);
   TF0=0;
}

   void delay20()
 { TH0=0x93;
   TL0=0xfd;
   TR0=1;
   while(TF0==0);
   TF0=0;
}