 #include<reg51.h>
 sbit en1=P2^0;
 sbit en2=P2^1;
 sbit en3=P2^2;
 sbit en4=P2^3;
 void delay(unsigned int a);
 int main()
 { unsigned char a[10]={0x3f,0x06,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77};
  unsigned int i;
  en1=1;
  en2=1;
  en3=1;
  en4=1;
  for(i=0;i<10;i++)
  { P0=a[i];
  //delay(200);
  }
  }
  void delay(unsigned int a)
{
unsigned int i,j;
for(i=0;i<=a;i++)
for(j=0;j<=255;j++);
}									 