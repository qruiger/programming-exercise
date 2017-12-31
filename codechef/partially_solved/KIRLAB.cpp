#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL int long long
LL gcd(LL a, LL b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
LL calc(LL a[],LL n)
{
	if(n==1)
	{
		return 1;
	}
	LL m=0,dp[n],j=0,i=1,k;
	for(k=0;k<n;k++)dp[k]=1;	
	while(1)
	{
		if(gcd(a[i],a[j])>1)
		{
			dp[i]=max((dp[j]+1),dp[i]);
		}
		j++;
		if(j==i)
		{
			j=0;
			i++;
		}
		if(j==n-1 && i==n)
		{
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		m=max(dp[i],m);
	}
	return m;	
}
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i;
		scanf("%lld",&n);
		LL a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		printf("%lld\n",calc(a,n));			  
	}
	return 0; 
} 