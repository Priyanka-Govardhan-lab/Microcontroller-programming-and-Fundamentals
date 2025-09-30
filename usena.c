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
	   { SBUF=a[i];
	    while(TI==0);
		TI=0;
		}
		if(strcmp(u,a)==0)

		{ printf("enter passward");
		   for(j=0;b[j]!='\0';j++)
		    { SBUF=b[j];
			  while(TI==0);
			  TI=0;
			if(strcmp(p,b)==0)
				 printf("corect");
				 else 
				 printf("invalis passwad");
		    }
		} 
		else 
		printf("invlid username");
	}