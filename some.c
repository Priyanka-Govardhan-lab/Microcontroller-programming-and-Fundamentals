				#include<reg51.h>
#include<stdio.h>
unsigned char r[5];
void uart()
{
TMOD=0X20;
TH1=0XFD;
SCON=0X50;
TR1=1;
}
void delay(unsigned int a)
{
unsigned int i,j;
for(i=0;i<a;i++)
for(j=0;j<=1255;j++);
}
void serial_tx(unsigned char s)
{
SBUF=s;
while(TI==0);
TI=0;
}
void rx()
{
unsigned int m;
for(m=0;r[m]!='\0';m++)
{
while(RI==0);
r[m]=SBUF;
RI=0;
}
serial_tx(r);
}


void send(char *z)
{
unsigned int k;
for(k=0;z[k]!='\0';k++)
{
serial_tx(z[k]);
}
}
void main()
{
uart();

send("AT\r\n");
send(0x0d);
delay(200);
rx();
delay(500);

send("AT+CMGF=1\r\n");
send(0x0d);

delay(200);
send("AT+CMGS=\"+918496926309\"\n");
send(0x0d);

delay(200);
send("hai");
send(0x1A);
while(1);

}