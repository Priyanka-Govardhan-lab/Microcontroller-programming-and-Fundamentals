									   #include<reg51.h>
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
sfr LCD=0x80;

void cmd (unsigned char b);
void lcddata (unsigned char c);
void delay (unsigned int a);
int main()

{
	unsigned char var;
	cmd (0x38);
	cmd (0x01);
	cmd (0x0e);
	cmd (0x80);

	P2=0x0f;
	while(1)
	{
		P2=0xef;
		var=P2;
		switch (var)
		{
			case 0xe7 : lcddata('1');
						break;
			case 0xed : lcddata('2');
						break;
			case 0xeb : lcddata('3');
						break;
			case 0xee : lcddata('4');
						break;
		 }

		P2=0xdf;
		var=P2;
		switch (var)
		{
			case 0xd7 : lcddata('5');
						break;
			case 0xdd : lcddata('6');
						break;
			case 0xdb : lcddata('7');
						break;
			case 0xde : lcddata('8');
						break;
		 }

		P2=0xbf;
		var=P2;
		switch (var)
		{
			case 0xb7 : lcddata('9');
						break;
			case 0xbd : lcddata('A');
						break;
			case 0xbb : lcddata('B');
						break;
			case 0xbe : lcddata('C');
						break;
		 }

		P2=0x7f;
		var=P2;
		switch (var)
		{
			case 0x77 : lcddata('D');
						break;
			case 0x7d : lcddata('E');
						break;
			case 0x7b : lcddata('F');
						break;
			case 0x7e : lcddata('0');
						break;
		 }
	   }
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
					delay(10);
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