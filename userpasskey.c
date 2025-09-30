#include<reg51.h>
#include<string.h>

unsigned char u[6];
unsigned char p[6];
unsigned char i;
unsigned char j;
sbit podd=P0^1;
sfr q=0x80;
void step();
sbit beepled=P1^0;
void delay (unsigned int a);

void tr(unsigned char *p)
{

for(i=0;p[i]!='\0';i++)
{
SBUF=p[i];			  
while(TI==0);
TI=0;
}							   
}

main()
{ 
IE=0x90;
SCON=0X50;
TMOD=0X20;
TH1=0XFD;  
TR1=1;
SBUF=' ';


while(TI==0);
TI=0;
while(1);

}
 void ser0 (void) interrupt 4
{


beepled=0;
podd=0;

SCON=0X50;
TMOD=0X20;
TH1=0XFD;  
TR1=1;
tr("\n hardware lock detected\n");



tr("\n enter the username\n");
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


if(strcmp(u,"hard")==0)
{
tr("\n enter the password \n");
for(j=0;j<7;j++)
{
while(RI==0);
p[j]=SBUF;
//SBUF=p[j];
RI=0;
if(p[j]==13)
{
p[j]='\0';
break;
}
}

tr(p);
}


if(strcmp(p,"1234")==0)
{ 
tr("\n password matched\n ");

step();
}


else
{  	
tr("unauthorised access \n");

while(1)
{
beepled=0;
delay(10);
beepled=1;
delay(10);
}

}
}


void step()


{  int i;
	for(i=0; i<50; i++)
	{
		P2=0x01;
		delay (10);
        P2=0x02;
		delay (10);
		P2=0x04;
		delay (10);
		P2=0x08;
		delay (10);
	}
	
}

void delay (unsigned int a)
                 {
                	unsigned int i,j;
 					for(i=0;i<=a;i++)
					  {
						for(j=0;j<255;j++);
					   }
				}



