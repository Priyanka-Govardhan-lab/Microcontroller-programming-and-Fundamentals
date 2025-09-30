	   #include<reg51.h>
	   sbit rs=P1^0	;
	   sbit rw=P1^1;
	   sbit en=P1^2;
   sfr LCD=0x80;
void delay (unsigned int a);
void lcdcom(unsigned char b);
void lcddata(unsigned char c);
int main()
	   {
	   //unsigned char str[10]="priyanka ";
	   //unsigned int i;
	    
	   lcdcom(0x28);
	    lcdcom(0x01);
		 lcdcom(0x0e);
		 lcdcom(0xC0);
		 

		 lcddata('A');
		 }
		 
void lcdcom(unsigned char b)
{ 
unsigned char d;
rs=0;
rw=0;
d=b&0xF0;
LCD=d;
en=1;
delay(100);
en=0;
d=b&0x0f;
d=d<<4;
LCD=d;
en=1;
delay(100);
en=0;
}
void lcddata(unsigned char c)
{ unsigned char e;
rs=1;
rw=0;
e=c&0xf0;
LCD=e;
en=1;
delay(100);
en=0;
e=c&0x0f;
e=e<<4;
LCD=e;
en=1;
delay(100);
en=0;
}
void delay(unsigned int a)
				{ unsigned int i,j;
				for(i=0;i<a;i++)
				for(j=0;j<=255;j++);
				}