#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000005
LL cs[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,m,w,x,y,z;
		scanf("%lld %lld",&n,&m);
		for(LL i=0;i<=n+5;i++)cs[i]=0;
		for(LL i=1;i<=m;i++)
		{
			scanf("%lld %lld %lld %lld",&w,&x,&y,&z);
			z=z*(3-(2*w));
			cs[x-1]+=z;
			cs[y]-=z;
		}	
		LL ans=0,minval=LLONG_MAX,maxval=LLONG_MIN;
		for(LL i=0;i<n;i++)
		{
			ans+=cs[i];
			minval=minval>(ans+i+1)?ans+i+1:minval;
			maxval=maxval<(ans+i+1)?ans+i+1:maxval;
		}
		printf("%lld\n",maxval-minval);
	}
	return 0; 
}