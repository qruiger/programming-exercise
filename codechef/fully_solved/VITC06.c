#include<stdio.h>
#define v 1000007
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int n,c;
		scanf("%lld",&n);
		c=(n-1);
		n=(n*(n+1))/2;
		n*=2;
		n+=((c+1)*(c))/2;
	  	printf("%lld\n",n%v);
	}
	return 0;
} 
