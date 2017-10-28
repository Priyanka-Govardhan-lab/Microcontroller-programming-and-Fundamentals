  #include<LPC17xx.h>
  void delay(unsigned int d);
  void lcdcmd(unsigned char c) ;
  void lcddata(unsigned char e)	;
 extern void pll();
  #define T3 LPC_TIM3
  #define P0 LPC_GPIO0
  main()
  { char  a,b,c,s[20],i;

  pll();
      LPC_SC->PCONP|=(1<<23);
  LPC_PINCON->PINSEL1=(3<<14);	 
  P0->FIODIR=(0x3f<<6);
  lcdcmd(0x28);
   lcdcmd(0x0e);
    lcdcmd(0x01);
	 lcdcmd(0x80);
	 //lcddata('a');
   //	p0.23  as cap3.0
  LPC_TIM3->PR=1500000;
  LPC_TIM3->CCR=(7<<0);
  LPC_TIM3->TCR=1;
  while(LPC_TIM3->IR&(1<<4)!=(1<<4));
  LPC_TIM3->IR=(1<<4);
  a=(LPC_TIM3->CR0);
   while(LPC_TIM3->IR&(1<<4)!=(1<<4));
  LPC_TIM3->IR=(1<<4);
  b=(LPC_TIM3->CR0);
c=a-b;
sprintf(s,"%d",c);
for(i=0;s[i]!='\0';i++)
{
lcddata( s[i]);
}

}

void lcdcmd(unsigned char c)
{
unsigned char temp;
 P0->FIOCLR=(1<<11);
  temp=((0xf0)&c);
  temp=temp>>4;
  P0->FIOCLR=(0XF<<6);
  P0->FIOSET=(temp<<6);
  P0->FIOSET=(1<<10);
  delay(10);
  P0->FIOCLR=(1<<10);

  temp=((0x0f)&c);
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
  temp=((0xf0)&e);
  temp=temp>>4;
  P0->FIOCLR=(0XF<<6);
  P0->FIOSET=(temp<<6);
  P0->FIOSET=(1<<10);
  delay(10);
  P0->FIOCLR=(1<<10);

  temp=((0x0f)&e);
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




  