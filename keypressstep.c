#include<reg51.h>
void delay (unsigned int a);
void anticlock (unsigned int b);

			   unsigned int b;
unsigned char x[5];

	unsigned char var;
void delay(unsigned int k)
{
unsigned int i,j;
for(i=0;i<k;i++)
{
for(j=0;j<125;j++);
}
}
void transmit(unsigned char *p)
{
unsigned int i;
for(i=0;p[i]!='\0';i++)
{
SBUF=p[i];
while(TI==0);
TI=0;
}
}
int receive()
{
unsigned int i,a=0,j=0;
for(i=0;i<5;i++)
{
while(RI==0);
x[i]=SBUF;
RI=0;
if(x[i]==13)
{
x[i]='\0';
break;
}
}
transmit(x);    
while(x[j]!='\0')
{
a=a*10+(x[j]-'0');
j++;
} 

//sscanf(x,"%d",&a);
return a;
}

int main()
		 
{	 transmit("enter");
	  b=receive();

		P2=0x0f;
	while(1)
	{
		P2=0xeb;
		var=P2;
		  	//b=receive();
		


	
		switch (var)

		{	 
	
					b=receive();

		
			case 0xe7 : anticlock(b/7);
						break;
			case 0xeb :  anticlock(b/7);
						break;
		}
	}
}

void anticlock (unsigned int x)

{
	  int i;
	for(i=0; i<(x); i++)
	{
		P0=0x01;
		//delay (10);
        P0=0x02;
		//delay (10);
		P0=0x04;
		//delay (10);
		P0=0x08;
		//delay (10);
	}
	//return 0;
}


//void clock (unsigned int b)
//
//{	   int i;
//	
//	for(i=0; i<b; i++)
//	{
//		P0=0x80;
//		//delay (10);
//        P0=0x40;
//		//delay (10);
//		P0=0x20;
//		//delay (10);
//		P0=0x01;
//		//delay (10);
//	}
//	//return 0;
//}
