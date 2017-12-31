#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000005
bool sieve[lim];
LL n,x,y,L,R,a[lim],q;
void primeGen()
{
	memset(sieve,true,sizeof(sieve));
	sieve[0]=false;
	sieve[1]=false;
	for(LL i=1;i<=sqrt(lim);i++)
	{
		if(sieve[i]==true)
		{	
			for(LL j=2*i;j<=lim;j+=i)
				sieve[j]=false;
		}
	}
}
LL solve()
{
	LL num,exp,ans=0;
	for(LL i=x;i<=y;i++)
	{
		if(sieve[i])
		{
			for(LL j=L;j<=R;j++)
			{
				num=a[j];
				exp=0;
				while(num%i==0)
				{
					exp=exp+1;
					num=num/i;
				}
				ans=ans+exp;
			}
		}
	}
	return ans;
}
int main()
{
	primeGen();
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&q);
	while(q--)
	{	
		scanf("%lld %lld %lld %lld",&L,&R,&x,&y);
		printf("%lld\n",solve());
	}
	return 0; 
}  
