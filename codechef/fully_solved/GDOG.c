#include<stdio.h>
int main()
{
	int T,i,c;
	long int n,k;
	scanf("%d",&T);
	while(T--)
	{
		c=0;
		scanf("%ld %ld",&n,&k);
		for(i=2;i<=k;i++)
		{
			if(c<(n%i))
				c=n%i;
		}		
		printf("%d\n",c);
	}
	return 0;
}
