#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL a[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i,maxval=-1;
		scanf("%lld",&n);
		for(LL i=1;i<=n;i++)
		{	
			scanf("%lld",&a[i]);
			maxval=max(maxval,a[i]);
		}
		printf("%lld\n",abs(n-maxval));
	}
	return 0; 
}