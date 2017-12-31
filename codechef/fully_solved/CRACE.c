#include<stdio.h>
int main()
{
	int T,i,rem,t;
	long int n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%ld",&n);
        	rem=n%5;
        	for(i=1;;i++)
        	{
        		if((5*i)+rem==n)
        		{	
             			t=i;
             			break;
            		}
        	}	 
        	if(t%2==0)
        	{
        		if(rem==0 || rem==2 || rem==4)
        			printf("JACK\n");
        		if(rem==1 || rem==3)
        			printf("JENNY\n"); 
		}
		if(t%2!=0)
		{
			if(rem==0 || rem==2 || rem==4)
        			printf("JENNY\n");
			if(rem==1 || rem==3)
        			printf("JACK\n"); 
	    	}
	}
	return 0;
}
