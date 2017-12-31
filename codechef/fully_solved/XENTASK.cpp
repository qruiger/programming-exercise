#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000005
LL x[lim],y[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i,sum1=0,sum2=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&x[i]);
		for(i=0;i<n;i++)
			scanf("%lld",&y[i]);
		for(i=0;i<n;i++)
		{
			if(i%2==0)
				sum1+=x[i];
			else
				sum1+=y[i];
		}
		for(i=0;i<n;i++)
		{
			if(i%2==0)
				sum2+=y[i];
			else
				sum2+=x[i];
		}
		printf("%lld\n",min(sum1,sum2));
	}
	return 0; 
} 