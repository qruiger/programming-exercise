#include<stdio.h>
#define LL long long int
int main()
{
	LL T;
	scanf("%lld",&T);
	while(T--)
	{
		LL diff,m,n;
		scanf("%lld %lld",&n,&m);
		if(n==m)
		{	
			printf("0\n");
			continue;
		}
		diff=n>m?n-m:m-n;
		printf("%lld\n",diff);
    }

}