#include<reg51.h>
sbit en1=P2^0;
sbit en2=P2^1;
sbit en3=P2^2;
sbit en4=P2^3;
unsigned delay(unsigned int a);
int main()
{
while(1)
{

unsigned char a[10]={0x3f,0x06,0x5b,0x4f,0x66,0xbd,0x07d,0x07,0x7f,0x6f};
unsigned int i;
en1=1;
/*en2=1;
en3=1;
en4=1;*/
for(i=0;i<9;i++)
{
P0=a[i];
delay(100);
}
en2=1
for(i=0;i<9;i++)
{
P0=a[i];
delay(100);
 for(i=0;i<59;i++)
{
P0=a[i];
delay(100);
}
}
