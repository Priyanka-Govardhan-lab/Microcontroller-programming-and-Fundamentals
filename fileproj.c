#include<reg51.h>
#include<file.h>
					  
 void main()		 

{ 
  		
  	   FILE *fp;
  fp=fopen("C:\Documents and Settings\ism.SYSTEM195.000\Desktop\hi.txt","r");
    fprintf(fp,"this id priya\n");
	fclose(fp);
  
  }