#include <bits/stdc++.h>
using namespace std;
#define LL int long long
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL i,a[100],ans=0,one,zero,len,n,m;
		scanf("%lld %lld",&n,&m);
		len=n+m-1;
		ans+=pow(2,len);
		for(i=len-m-1;i>=0;i--)
		{
			ans+=pow(2,i);
		}
		printf("%lld\n",ans);
	}
	return 0; 
} 