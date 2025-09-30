			  #include<lpc17xx.h>
extern void pll();
#define T3 LPC_TIM3
#define P0 LPC_GPIO0
void delay(unsigned int d);
void lcdcom( unsigned char c);
void lcddata(unsigned char e);
unsigned char a,b;
unsigned char s[12];
unsigned int i;
int main()
{
pll();
P0->FIODIR=(0X3F<<6);
lcdcom(0x28);
lcdcom(0x01);
lcdcom(0x0e);
lcdcom(0x80);

LPC_PINCON->PINSEL1=(3<<16);
LPC_SC->PCONP|=(1<<23);

T3->PR=15000000;
T3->CCR=(7<<3);
T3->TCR=(1<<0);
 

while((T3->IR&(1<<5))!=(1<<5));
T3->IR=(1<<5);
 a=T3->CR1;
lcddata('B'); 
 while((T3->IR&(1<<5))!=(1<<5));
T3->IR=(1<<5);
b=T3->CR1;
b=b-a;
sprintf(s,"%d",b);
for(i=0;s[i]!='\0';i++)
{
lcddata( s[i]);
}

}

void lcdcom(unsigned char c)
{
unsigned char temp;
 P0->FIOCLR=(1<<11);
  temp=(0xf0)&c;
  temp=temp>>4;
  P0->FIOCLR=(0XF<<6);
  P0->FIOSET=(temp<<6);
  P0->FIOSET=(1<<10);
  delay(10);
  P0->FIOCLR=(1<<10);

  temp=(0x0f)&c;
  P0->FIOCLR=(0XF<<6);
  P0->FIOSET=(temp<<6);
  P0->FIOSET=(1<<10);
  delay(10);
  P0->FIOCLR=(1<<10);
  }
  void lcddata(unsigned char e)
{
unsigned char temp;
 P0->FIOSET=(1<<11);
  temp=(0xf0)&e;
  temp=temp>>4;
  P0->FIOCLR=(0XF<<6);
  P0->FIOSET=(temp<<6);
  P0->FIOSET=(1<<10);
  delay(10);
  P0->FIOCLR=(1<<10);

  temp=(0x0f)&e;
  P0->FIOCLR=(0XF<<6);
  P0->FIOSET=(temp<<6);
  P0->FIOSET=(1<<10);
  delay(10);
  P0->FIOCLR=(1<<10);
  }
  void delay(unsigned int d)
  {
  int i,j;
  for(i=0;i<=d;i++)
  for(j=0;j<=5000;j++);
  }


