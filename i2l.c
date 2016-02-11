	   #include<LPC17xx.h>
	#define I2 LPC_I2C2
	extern void pll(void);
		void i2cinit(void)
	{
	 LPC_PINCON->PINSEL0=(2<<20)|(2<<22);
	 LPC_PINCON->PINMODE0=(2<<20)|(2<<22);
	 LPC_PINCON->PINMODE_OD0=(3<<10);
	 LPC_I2C2->I2SCLL=75;
	 LPC_I2C2->I2SCLH=75;
	 }

	void lcdcmd(unsigned char a);
	void lcddata(unsigned char b);
	main()
	{
	 pll();
	 i2cinit();
	 lcdcmd(0x28);
	 lcdcmd(0x0e);
	 lcdcmd(0x01);
	 lcdcmd(0x80);
	 lcdcmd(0x80);
	 lcddata('s');
	 while(1);
	}
	void lcdcmd(unsigned char a)
	{
	 unsigned char temp;
	 I2->I2CONSET=(1<<5)|(1<<6);
	 while(I2->I2STAT!=0x08);
	 I2->I2CONCLR=(1<<3)|(1<<5);

	 I2->I2DAT=0x4e;
	 while(I2->I2STAT!=0x18);
	 I2->I2CONCLR=(1<<3);


	 temp=(a&(0xf0));

	 I2->I2DAT=(temp|0x0C);
	 while(I2->I2STAT!=0x28);
	 I2->I2CONCLR=(1<<3);

	 I2->I2DAT=(temp|0x0C);
	 while(I2->I2STAT!=0x28);
	 I2->I2CONCLR=(1<<3);

	 I2->I2DAT=(temp|0x08);
	 while(I2->I2STAT!=0x28);
	 I2->I2CONCLR=(1<<3);

	  temp=((a&(0x0f))<<4);

	 I2->I2DAT=(temp|0x0C);
	 while(I2->I2STAT!=0x28);
	 LPC_I2C2->I2CONCLR=(1<<3);

	  LPC_I2C2->I2DAT=(temp|0X0C);
      while(LPC_I2C2->I2STAT!=0x28);
	  LPC_I2C2->I2CONCLR=(1<<3);

	  LPC_I2C2->I2DAT=(temp|0X08);
	while(LPC_I2C2->I2STAT!=0x28);
	 I2->I2CONCLR=(1<<3);

	 I2->I2CONSET=(1<<4);
	 I2->I2CONCLR=0xff;
	}
	void lcddata(unsigned char b)
	{ 
	unsigned char temp;
	I2->I2CONSET=(1<<5)|(1<<6);
	while(I2->I2STAT!=0x08);
	I2->I2CONCLR=(1<<3)|(1<<5);
	I2->I2DAT=0x4e;
	while(I2->I2STAT!=0x18);
	I2->I2CONCLR=(1<<3);

	temp=(b&(0xf0));

	I2->I2DAT=(temp|0x0d);
	while(I2->I2STAT!=0x28);
	I2->I2CONCLR=(1<<3);

	I2->I2DAT=(temp|0x0d);
	while(I2->I2STAT!=0x28);
	I2->I2CONCLR=(1<<3);

	I2->I2DAT=(temp|0x09);
	while(I2->I2STAT!=0x28);
	I2->I2CONCLR=(1<<3);

	temp=((b&0x0f)<<4);

	I2->I2DAT=(temp|0x0d);
	while(I2->I2STAT!=0x28);
    I2->I2CONCLR=(1<<3);

	I2->I2DAT=(temp|0x0d);
	while(I2->I2STAT!=0x28);
	I2->I2CONCLR=(1<<3);

	I2->I2DAT=(temp|0x09);
	while(I2->I2STAT!=0x28);
	I2->I2CONCLR=(1<<3);

	I2->I2CONSET=(1<<4);
	I2->I2CONCLR=0xff;
    }


