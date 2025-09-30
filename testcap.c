#include<lpc17xx.h>
#define P0 LPC_GPIO0


void pll()
{
LPC_SC->SCS=(1<<5);
while ((LPC_SC->SCS&(1<<6)==0));
LPC_SC->CLKSRCSEL=(1<<0);				                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
LPC_SC->PLL0CON=(1<<0);
LPC_SC->PLL0CFG=(14<<0); //PLL FREQ=360MHz, CPU FREQ=60Hz
LPC_SC->PLL0FEED=0XAA;
LPC_SC->PLL0FEED=0X55;
LPC_SC->CCLKCFG=(5<<0);
while ((LPC_SC->PLL0STAT&(1<<26))==0);
LPC_SC->PLL0CON|=(1<<1);
LPC_SC->PLL0FEED=0XAA;
LPC_SC->PLL0FEED=0X55;
}

int capture ()
{
unsigned int t,x,y;
LPC_TIM3->PR=(14999<<0);
LPC_TIM3->CCR=(0X07<<0);
LPC_TIM3->TCR=(1<<0);
while ((LPC_TIM3->IR&(1<<4))==0);
x = LPC_TIM3->CR0;
LPC_TIM3->IR=(1<<4);
while ((LPC_TIM3->IR&(1<<4))==0);
y = LPC_TIM3->CR0;
LPC_TIM3->IR=(1<<4);
t=y-x;
return t;
}


void delay (unsigned int k)
{
int i,j;
for (i=0;i<k;i++)
for (j=0;j<250;j++);
}


void lcd_cmd (unsigned char a)
{
unsigned char temp;
P0->FIOCLR=(1<<10);
temp =a & 0xF0;
P0->FIOCLR=(0X0F<<6);
P0->FIOSET=(temp<<2);
P0->FIOSET=(1<<11);
delay(100);
P0->FIOCLR=(1<<11);
delay(100);

temp=a & 0X0F;
 temp=temp>>4;
P0->FIOCLR=(0X0F<<6);
P0->FIOSET=(temp<<6);
P0->FIOSET=(1<<11);
delay(100);
P0->FIOCLR=(1<<11);
delay(100);
}

void lcd_data (unsigned char b)
{
unsigned char temp1;
P0->FIOSET=(1<<10);
temp1= b & 0xF0;
P0->FIOCLR=(0X0F<<6);
P0->FIOSET=(temp1<<2);
P0->FIOSET=(1<<11);
delay(100);
P0->FIOCLR=(1<<11);
delay(100);

temp1= b & 0X0F;
 temp1=temp1>>4;
P0->FIOCLR=(0X0F<<6);
P0->FIOSET=(temp1<<6);
P0->FIOSET=(1<<11);
delay(100);
P0->FIOCLR=(1<<11);
delay(100);
}

int main()
{
unsigned int d;
char i,buf[12] = {0};
P0->FIODIR=(0X3F<<6);
lcd_cmd (0X28);
lcd_cmd (0X0E);
lcd_cmd (0X01);
lcd_cmd (0X80);
lcd_data('k');

LPC_SC->PCONP|=(1<<23);
LPC_PINCON->PINSEL1=(0X03<<14);
pll();

d=capture();
sprintf(buf,"%d",d);
for(i = 0;buf[i]!='\0';i++)
lcd_data (buf[i]);
while (1);


}
