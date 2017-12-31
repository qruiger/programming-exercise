#include <bits/stdc++.h>
#define LL int long long
using namespace std;
#define lim 5000005
LL n,i,j;
bool sieve[lim];
int main()
{
	LL t;
	scanf("%lld",&t);
	memset(sieve,true,sizeof(sieve));
	sieve[0]=false;
	sieve[1]=false;
	for(i=2;i<=sqrt(lim);i++)
	{
		if(sieve[i]==true)
		{
			for(j=i*2;j<=lim;j+=i)
				sieve[j]=false;
		}
	}
	while(t--)
	{
		LL L,R,sum=0;
		scanf("%lld %lld",&L,&R);
		for(i=L;i<=R;i++)
		{
			if(sieve[i])
				sum+=i;
		}
		printf("%lld\n",sum);
	}
}