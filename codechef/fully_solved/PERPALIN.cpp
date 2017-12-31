#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL n,p,x;
void generic(LL n)
{
	LL x=n-2;
	printf("a");
	for(LL i=1;i<=x;i++)
		printf("b");
	printf("a");
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&p);
		if(n<=2 || p<=2)
		{
			printf("impossible\n");
			continue;
		}
		if(n==p)
			generic(n);
		else
		{
			for(LL i=1;i<=n/p;i++)
				generic(p);
		}
		printf("\n");		
	}
	return 0; 
}