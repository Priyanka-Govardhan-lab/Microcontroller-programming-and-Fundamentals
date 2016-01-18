				  #include <reg51.h>
				  sbit RS=P1^0;
				  sbit RW=P1^1;
				  sbit EN=P1^2;
				  sfr LCD=0x80;
				  void delay (unsigned int a);
				  unsigned char a[10]="haibengal";
				  void cmd (unsigned char b);
				  void lcddata (unsigned char c);
				  int i;
				  int main()
				  {
				  	cmd (0x38);
					cmd (0x01);
					cmd (0x0e);
					cmd (0x80);
					for(i=0;i<10;i++)
					lcddata(a[i]);
					
					return 0;
				  }

				 void cmd (unsigned char b)
				 {
				 	RS=0;
					RW=0;
					LCD=b;
					EN=1;
					delay(10);
					EN=0;
				 }

				  void lcddata(unsigned char c)
				 {
				 	RS=1;
					RW=0;
					LCD=c;
					EN=1;
					delay(100);
					EN=0;
				 }

				 void delay (unsigned int a)
                 {
                	unsigned int i,j;
 					for(i=0;i<=a;i++)
					  {
						for(j=0;j<255;j++);
					   }
				}