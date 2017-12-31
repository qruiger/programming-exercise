#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
#define mod 1000000007
LL a[lim];
LL calc(LL term,LL k)
{
	LL ans=0;
	LL x=a[1];
	if(x==k)
		ans++;
	for(LL i=2;i<=term;i++)
	{
		x=x^a[i];
		if(x==k)
			ans++;
	}
	return ans;
}
int main()
{
	LL n,i,k,q,x;int type;
	scanf("%lld %lld",&n,&q);
	for(LL i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	while(q--)
	{
		scanf("%d",&type);
		if(type==1)
		{
			scanf("%lld %lld",&i,&x);
			a[i]=x;
		}
		if(type==2)
		{
			scanf("%lld %lld",&i,&k);
			printf("%lld\n",calc(i,k));
		}
	}
	return 0; 
} 
