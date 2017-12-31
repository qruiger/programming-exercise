#include <bits/stdc++.h>
using namespace std;
#define LL int long long
LL a[2000005];
struct store
{
	LL val,rept;
};
LL calc(LL n)
{
	LL temp,e=0,o=0;
	while(n>0)
	{
		temp=n%10;
		temp%2==0?e+=temp:o+=temp;
		n/=10;
	}
	return abs(e-o);
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL k=1,n,ans=0,mul=1,fill=2;
		scanf("%lld",&n);
		store a[2*n+1];
		for(LL i=1;i<=2*n-1;fill++,i++,k++)
		{
			a[k].val=fill;
			a[k].rept=mul;
			if(fill>=n+1)
				mul--;
			else
				mul++;
		}
		for(LL i=1;i<=2*n-1;i++)
			ans+=(a[i].rept)*(calc(a[i].val));
		printf("%lld\n",ans);
	}
	return 0; 
} 