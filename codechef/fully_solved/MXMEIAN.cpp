#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL a[lim],b[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i;
		scanf("%lld",&n);
		LL N=2*n;
		for(LL i=1;i<=N;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+N+1);
		LL ind=1;
		for(LL i=(N-n)+1;i<=N;i++)
			b[ind++]=a[i];
		double val=ceil(1.0*n/2);
		LL op=(LL)val;		
		printf("%lld\n",b[op]);
		for(i=1;i<=n;i++)
			printf("%lld %lld ",a[i],b[i]);
		printf("\n");
	}
	return 0; 
} 