  #include<reg51.h>
  int asciitodec( unsigned char x)
  main()
  { SCON=0x50;
    TH1=-3;
	IE=0x90;
	TMOD=0X20;
    TR1=1;
	while(1);
	}

	void serial(void) interrupt 4;
	{ unsigned char a;
	unsigned int b=0,i;
	while(RI==0);
	 a=SBUF;
      b=asciitodec(a);
	b=b/7;
	for(i=0;i<b;i++)
	{ P0=0x01;
	P0=0x02;
	P0=0x04;
	P0=0x08;
	}
	}

   int asciitodec( unsigned char x)
   
