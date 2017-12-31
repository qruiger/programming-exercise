#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 10005
#define mod 1000000007
LL a[lim][lim],t,nq,n;
void find()
{
	LL var,mmin=LLONG_MAX,j=0;
	for(LL i=1;i<=n;i++)
	{
		var=(a[i][0])+(a[i][1]*t)+(a[i][2]*t*t)+(a[i][3]*t*t*t);
		if(var<mmin)
			mmin=var;
	}
	printf("%lld\n",mmin);
}
int main()
{
	LL T; 
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(LL i=1;i<=n;i++)
		{
			for(LL j=0;j<4;j++)
				scanf("%lld",&a[i][j]);
		}
		scanf("%lld",&nq);
		for(LL i=1;i<=nq;i++)
		{
			scanf("%lld",&t);
			find();
		}	
	}
	return 0; 
} 