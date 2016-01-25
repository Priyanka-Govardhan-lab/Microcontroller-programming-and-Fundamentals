#include<lpc17xx.h>
void delay(unsigned int a)
{
unsigned int i,j;
for(i=0;i<a;i++)
for(j=0;j<500;j++);
}

void lcdcmd(unsigned char b)
{
unsigned char temp;
LPC_GPIO0->FIOCLR=(1<<11);	//rs=0
temp=(0xf0)&b;
temp=temp>>4;
LPC_GPIO0->FIOCLR=(0x0f<<6);	 //clearing all the bits intially
LPC_GPIO0->FIOSET=(temp<<6);
LPC_GPIO0->FIOSET=(1<<10); //en=1
delay(100);
LPC_GPIO0->FIOCLR=(1<<10); //en=0
delay(100);
temp=(0x0f)&b;
LPC_GPIO0->FIOCLR=(0x0f<<6);
LPC_GPIO0->FIOSET=(temp<<6);
LPC_GPIO0->FIOSET=(1<<10); //en=1
delay(100);
LPC_GPIO0->FIOCLR=(1<<10); //en=0
delay(100);
}
void lcddata(unsigned char c)
{
unsigned char temp;
LPC_GPIO0->FIOSET=(1<<11);	//rs=1
temp=(0xf0)&c;
temp=temp>>4;
LPC_GPIO0->FIOCLR=(0x0f<<6);	 //clearing all the bits intially
LPC_GPIO0->FIOSET=(temp<<6);
LPC_GPIO0->FIOSET=(1<<10); //en=1
delay(100);
LPC_GPIO0->FIOCLR=(1<<10); //en=0
delay(100);
temp=(0x0f)&c;
LPC_GPIO0->FIOCLR=(0x0f<<6);
LPC_GPIO0->FIOSET=(temp<<6);
LPC_GPIO0->FIOSET=(1<<10); //en=1
delay(100);
LPC_GPIO0->FIOCLR=(1<<10); //en=0
delay(100);
}
unsigned int flag;
unsigned char str[20]="P^2SR";
main()
{
unsigned int i;
LPC_PINCON->PINSEL4=(1<<20);//Selecting external interrupt0 at p2.10
//unsigned int i;
LPC_GPIO0->FIODIR=(0x3f<<6);//To set the direction of lcd pins p0.6 to p0.11
LPC_SC->EXTMODE=(1<<0);
LPC_SC->EXTPOLAR=(1<<0);
lcdcmd(0x28);
lcdcmd(0X0e);
lcdcmd(0X01);
lcdcmd(0x80);
NVIC_EnableIRQ(18);
while(1)
{
if(flag==1)
{
	for(i=0;str[i]!='\0';i++)
	{
	lcddata(str[i]);
	}
}
flag=0;
}
}
void EINT0_IRQHandler()
{
flag=1;
LPC_SC->EXTINT=(1<<0);
}