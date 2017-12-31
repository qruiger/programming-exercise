#include<stdio.h>
int main()
{
	long long int T,n,k,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
     		k=n;
     		j=n*(n+1)/2;
     		printf("%lld\n",j+k);
	}
	return 0; 
}
 
