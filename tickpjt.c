#include<reg51.h>
int	 rfid()
		 { int cardid[50];int d ;
		  for (d=0;d<12;d++)
		  {while(RI==0);
		  cardid[d]= SBUF;
		  RI=0;}
		 return cardid;
		  }
////		  	
int rx()
{//for(i=0;i<12;i++)
  int a;
while(RI==0);
   a=SBUF;
SBUF=a;
RI=0  ;
return a;
}
   
void delay(unsigned int e)
{
unsigned int i,j;
for(i=0;i<e;i++)
for(j=0;j<1275;j++);
}



void tx(unsigned char *p)
{
   int i;
for(i=0;p[i]!='\0';i++)
{
SBUF=p[i];			  
while(TI==0);
TI=0;
}							   
}
  
  
  int main()
{	 
int S,D,X,Y,Z;
 int cardid[50],d;
SCON=0x50;
TMOD=0x20;
TH1=-3;		//-3=fd
TR1=1;
tx("WELCOME TO METRO");
tx("\r\n");
delay(100);
tx("STATIONS ARE");
tx("\r\n");
tx("1)X 2)Y 3)Z");
tx("\r\n");
tx("boarding  at :");
S=rx();
tx("\r\n");
tx("deboarding at  :");
D=rx();
tx("\r\n");
if(S=='1')
tx(" WELCOME TO x  ");
if(S=='2')
tx("WELCOME TO  Y ");
if(S=='3')
tx("WELCOME TO  z ");
tx("\r\n");
if(D=='1')
tx("collect ticket to X ");
if(D=='2')
tx(" collect Ticket to Y ");
if(D=='3')
tx("collect ticket to Z");
tx("\r\n");
tx("SWIPE THE CARD");

for (d=0;d<12;d++)
		  {while(RI==0);
		  cardid[d]= SBUF;
		  RI=0;}
		  
		  tx(cardid);  //scanned id card

switch(S)
{
case '1':
           if (D=='1')
		   tx("invalid ");
		   
		   if(D=='2')
	{
		Y=rfid();
		if(Y==cardid)
		tx("\r\nA Access granted");
		
	else
		tx("\r\nA Access denied");
		}

		if(D=='3')
	{
		Z=rfid();
		if(Z==cardid)
		tx("\r\nA Access granted");
		
	else
		tx("\r\nA Access denied");}
	break;
	     
case '2':if (D=='2')
        tx("invalid");
		
		if(D=='1')
	{
		X=rfid();
		if(X==cardid)
		tx("\r\nA Access granted");
		
	else
		tx("\r\nA Access denied");
		}

		if(D=='3')
	{
		Z=rfid();
		if(Z==cardid)
		tx("\r\nA Access granted");
		
	else
		tx("\r\nA Access denied");}
	break;


case '3':if(D=='3')
           tx("invaid");
		   if(D=='2')
	{
		X=rfid();
		if(X==cardid)
		tx("\r\nA Access granted");
		
	else
		tx("\r\nA Access denied");
		}

		if(D=='1')
	{
		Y=rfid();
		if(Y==cardid)
		tx("\r\nA Access granted");
		
	else
		tx("\r\nA Access denied");}
	break;
 
}



while(1);			
}



