#include<reg51.h>
sbit A2=P2^0;
sbit A1=P2^1;
sbit A0=P2^2;
sbit b=P3^0;

sbit start=P2^3;
sbit ale=P2^4;
sbit eoc=P2^5;
sbit oe=P2^6;

sbit rs=P3^7;
sbit rw=P3^6;
sbit en=P3^5;
sfr lcd=0x80;

void delay(unsigned int a);
void lcdcom(unsigned char b);
void lcddata(unsigned char c);
void adc();
void ascii (unsigned int value);
unsigned char a[4];
int main()
{A2=0;A1=0;A0=0;
ale=0;
oe=0;
eoc=1;
lcdcom(0x38);
lcdcom(0x01);
lcdcom(0x0e);
lcdcom(0x80);
while(1)
{
adc();
}
}
void adc()
{
unsigned int temp;
ale=1;
delay(10);
start=1;
delay(10);
ale=0;
delay(10);
start=0;
while(eoc==1);
while(oe==1);
oe=1;
temp=P1;
if(temp>0x5f)
b=0xff;
else 
b=0x00;
ascii(temp);
oe=0;
delay(500);
lcdcom(0x01);
}
void ascii(unsigned int value)
{
int y=0,j=0;
y=value;
while(y!=0)
{
a[j]=y%10+'0';
y=y/10;
j++;
}
for(j=j-1;j>=0;j++)
{
lcddata(a[j]);
}
}
void lcdcom(unsigned char b)
{
rs=0;
rw=0;
lcd=b;
en=1;
delay(100);
en=0;
}
void lcddata(unsigned char c)
{
rs=1;
rw=0;
lcd=c;
en=1;
delay(10);
en=0;
}
void delay(unsigned int a)
{
unsigned int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=255;j++);
}
