			   #include<reg51.h>
	 #include<string.h>
	 #include<stdio.h>
	 main()
	 { char u[5]="abcd";
	   char p[4]="xyz";
	   char a[10]="abcd",b[10]="xyz";
	   int i,j;
	   TMOD=0x20;
	   TH1=0xfd;
	   SCON=0x50;
	   TR1=1;
	   for(i=0;a[i]!='\0';i++)
	   { 
	    while(RI==0);
		SBUF=a[i];
         a[i]=SBUF;
		SBUF=a[i];

		RI=0;
		}
		if(strcmp(u,a)==0)

		{ SBUF='p';
		   for(j=0;b[j]!='\0';j++)
		    { 
			  while(RI==0);
			  b[j]=SBUF;
			  SBUF=b[j];
			  RI=0;
			if(strcmp(p,b)==0)
				 SBUF='c' ;
				 
		    }
		} 
		else 
		printf("invlid username");
	}