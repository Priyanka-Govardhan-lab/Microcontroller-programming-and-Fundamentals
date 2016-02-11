							   #include<lpc17xx.h>
#include"pll.c"
void stepper (unsigned char x);
void delay(unsigned int a);
char x[10],i;
int main()
{
unsigned int a,j;
LPC_GPIO0->FIODIR=(0XF<<6);
LPC_PINCON->PINSEL0=(1<<4)|(1<<6);
  pll();
   LPC_UART0->LCR=(3<<0)|(1<<7);
   LPC_UART0->DLL=97;
   LPC_UART0->DLM=0;
   LPC_UART0->LCR &=~(1<<7);

   do
			{
  while((LPC_UART0->LSR&(1<<0))!=(1<<0));
 	   x[i]=LPC_UART0->RBR;
	  
   while((LPC_UART0->LSR&(1<<5))!=(1<<5));
   LPC_UART0->THR=x[i];
  	   } while(x[i]==13)

	    sscanf(a ,"%d" ,x);
		
	   
   	  stepper(a);
	  
	  
	  while(1);
	  }		
	
   void stepper(unsigned char x)
  {
  unsigned int i;
  
  
  for(i=0;i<=x;i++)
  {
  LPC_GPIO0->FIOSET=(0X01<<6);
 delay(10);
  LPC_GPIO0->FIOCLR=(0X01<<6);
   LPC_GPIO0->FIOSET=(0X02<<6);
  delay(10);
  LPC_GPIO0->FIOCLR=(0X02<<6);
   LPC_GPIO0->FIOSET=(0X04<<6);
  delay(10);
  LPC_GPIO0->FIOCLR=(0X04<<6);

	 LPC_GPIO0->FIOSET=(0X08<<6);
  delay(10);
  LPC_GPIO0->FIOCLR=(0X08<<6);

  }
  }
  	 void delay(unsigned int a)
{
int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=250;j++);
}