#include<reg51.h>
unsigned char a;
main()
{ TMOD=0x20;
SCON=0x50;
TH1=0xfd;
TR1=1;
while(1)
{while(RI==0);
   
   a=SBUF;
SBUF=a;
RI=0;}
}