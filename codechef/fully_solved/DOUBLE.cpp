#include<stdio.h>
#define LL int long long
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL n;
		scanf("%lld",&n);
		if(n%2==0)
			printf("%lld\n",n);
		else
			printf("%lld\n",n-1);
	}
	return 0;
}