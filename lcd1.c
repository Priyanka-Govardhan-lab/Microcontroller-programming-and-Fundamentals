	   #include<reg51.h>
	   sbit RS =P1^0;
	   sbit RW=P1^1;
	   sbit en= P1^2;
	   sfr LCD=0x80;
	   void delay(unsigned int a);
	   void lcdcmd(unsigned char b);
	   void lcddata(unsigned char c);
	   int main()
	   {
	   unsigned char str[10]="priyanka ";
	   unsigned int i;
	    
	   lcdcmd(0x38);
	    lcdcmd(0x01);
		 lcdcmd(0x0e);
		 lcdcmd(0x80);
		 

		 lcddata(str);
		 }

		 void lcdcmd(unsigned char b)
		 { RS=0;
		 RW=0;
		 LCD=b;
		 en=1;
	     delay(67);
		 en=0;
		 }

		   void lcddata(unsigned char *c)
		 { 
		 int x;
		 RS=1;
		 RW=0;
		 for(x=0;c[x]!='\0';x++)

		{ LCD=c[x];
		 en=1;
		delay(67);
		 en=0;}
		 }

			  void delay(unsigned int a)
				{ unsigned int i,j;
				for(i=0;i<a;i++)
				for(j=0;j<=255;j++);
				}