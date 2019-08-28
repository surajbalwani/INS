#include<stdio.h>

void main()
{
	int p,q,n,fi_n,assume_e,e,i=1,assume_d=0,d,gcd=0,b=0;
	
	printf("\nEnter the value of p : ");
	scanf("%d",&p);
	
	printf("\nEnter the value of q : ");
	scanf("%d",&q);
	
	n = p * q;
	
	printf("\nn is calculated as : %d",n);
	
	fi_n = (p - 1)*(q - 1);
	
	printf("\nfi of n is calculated as : %d",fi_n);
	
	for(assume_e = 2; assume_e < fi_n; assume_e++)
	{
    	if(assume_e%i==0 && fi_n%i==0)
        	gcd = i;
        if(gcd == 1)
        {
        	e = assume_e;
        	printf("in for loop e : %d",e);
        	b = 1;       		
        }
   	}
   	
    printf("\ne is calculated as : %d",e);
    
    while(1)
    {
    	if(((e*assume_d) % fi_n)==1)
    	{
 	    	d = assume_d;
 	    	break;
 	    }
    	else
    		assume_d++;
    }
    
    printf("\nd is calculated as : %d\n",d);
}
