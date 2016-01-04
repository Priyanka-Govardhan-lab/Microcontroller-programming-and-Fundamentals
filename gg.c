  #include<lpc17xx.h>
#include"pll.c"
void stepper (unsigned int x);
void delay(unsigned int a);
char x[10];
int main()
{
unsigned int a=0,j,i = 0;
unsigned char m[12] = 0;
LPC_GPIO0->FIODIR=(0XF<<6);
LPC_PINCON->PINSEL0=(1<<4)|(1<<6);
  pll();
   LPC_UART0->LCR=(3<<0)|(1<<7);
   LPC_UART0->DLL=97;
   LPC_UART0->DLM=0;
   LPC_UART0->LCR &=~(1<<7);
  	i=0;
  while(1)    //charecter size
	{
  		do{while((LPC_UART0->LSR&(1<<0))!=(1<<0));
 	    x[i]=LPC_UART0->RBR;
	  	while((LPC_UART0->LSR&(1<<5))!=(1<<5));
   		LPC_UART0->THR=x[i];
		 }while(x[i]!=13);
  	 }  
	
	
	sscanf(x,"%d",&a);

   	  stepper(a);
	  
	   i=0;
	}
			
	
   void stepper(unsigned int x)
  {
  unsigned int i;
 for(i=0;i<=(x/7.2);i++)
  {
  LPC_GPIO0->FIOSET=(0X1<<6);

  delay(10);
  LPC_GPIO0->FIOCLR=(0X1<<6);

 
   LPC_GPIO0->FIOSET=(0X2<<6);
  delay(10);
  LPC_GPIO0->FIOCLR=(0X2<<6);


   LPC_GPIO0->FIOSET=(0X4<<6);
  delay(10);
  LPC_GPIO0->FIOCLR=(0X4<<6);

 
	 LPC_GPIO0->FIOSET=(0X8<<6);
  delay(10);
  LPC_GPIO0->FIOCLR=(0X8<<6);

 
  }
  }
  	 void delay(unsigned int a)
{
int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=2500;j++);
}