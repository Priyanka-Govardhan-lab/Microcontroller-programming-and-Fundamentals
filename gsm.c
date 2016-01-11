#include<reg51.h>
			unsigned int k=1,i;
			char str[26];
			char gsmw[3]="AT";
			char c1[14]="AT+CMGF=1\r";
			char c2[40] ="AT+CMGS=\"+918496926309\"\r";
			char msg[10]="123456";
	        void response();
			void delay(unsigned int a);
	  
void tr(unsigned char *p)
{for(i=0;p[i]!='\0';i++)
  {SBUF=p[i];			  
  while(TI==0);
    TI=0;
  }							   
}

void gr()
{   while(RI==0);
str[k]=SBUF;
RI=0;
}
main()
{	  
	TMOD=0x20;
	TH1=0xfd;
	SCON=0x50;
	TR1=1;
	tr("interfacing gsm");
	//while(1)
	tr(gsmw);
     tr(13);
	 delay(6000);
     gr();
	 response();

	 tr(c1);
    tr(0x0d);
	delay(6000);
	gr();
	response();

    tr(c2);
	 tr(0x0d);
	delay(6000);
	gr();
	response();

    
	 tr(msg);
	 tr(0x01a);
	 delay(5000);
		

}

   void response()
   { while(1)
   if((str[k-1]=='O') && (str[k]=='K'))
     {tr(str);
	 break;
	  }
	  k=k+1;
	 }
      	  void delay(unsigned int a)
{
unsigned int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=255;j++);
}
	