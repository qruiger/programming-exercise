#include<stdio.h>
int main()
{
	int n1,n2,T,a,b,lcm;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		n1=a;
		n2=b;
		while(a!=b)
	   	{
			if(a>b)
				a-=b;
			else
				b-=a;
	    	}
		lcm=(n1*n2)/a;
		printf("%d\t%d\n",a,lcm);
    	}
}
