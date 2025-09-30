


#include<reg51.h>
unsigned char x[5];
unsigned int b;
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
main()
{
unsigned int k;
SCON=0x50;
TMOD=0x20;
TH1=0xfd;
TR1=1;
transmit("ENTER THE ANGLE\n");
b=receive();
b=b/7;
while(1)
{
for(k=0;k<b;k++)
{
P0=0x10;
delay(10);
P0=0x20;
delay(10);
P0=0x40;
delay(10);
P0=0x80;
delay(10);
}
}
}

