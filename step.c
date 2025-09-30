#include<reg51.h>
void delay(unsigned int a);	
void ascii(unsigned int value)	 ;
void tr(unsigned char *p) ;

main()
{	unsigned int i,j;
     unsigned int x;
 
   unsigned char u[6];
SCON=0X50;
TMOD=0X20;
TH1=0XFD;  
TR1=1;
	tr("enter the angle");
	for(j=0;j<6;j++)
{

while(RI==0);
u[j]=SBUF;
//SBUF=u[j];
RI=0;
if(u[j]==13)

{
u[j]='\0';
break;
}
}

tr(u);
}

//ascii(u);
//
//
//
//for(i=0;i<(x/7);i++)
//{ P0=0x01;
//		delay (10);
//        P0=0x02;		   
//		delay (10);
//		P0=0x04;
//		delay (10);
//		P0=0x08;
//		delay (10);
//	}
//
//}
	  
void delay(unsigned int a)
{
unsigned int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=255;j++);
}	

	void tr(unsigned char *p)
{
unsigned char i;
for(i=0;p[i]!='\0';i++)
{
SBUF=p[i];			  
while(TI==0);
TI=0;
}	
}						   

void ascii(unsigned int value)
{	  unsigned char a[6];
int y=0,j=0;
y=value;
while(y!=0)
{
a[j]=y%10+'0';
y=y/10;
j++;
}		                    

tr(a);

}

