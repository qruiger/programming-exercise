#include<bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000005
LL a[lim];
int main()
{
	LL n,i,q,a,b,a1,b1;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld %lld",&a1,&b1);
		a=min(a1,b1);
		b=max(a1,b1);
		if(a%2==0 && b%2==0)
		{
			if(b-a==2)
			{
				printf("YES\n");
				continue;
			}
		}
		if(a%2!=0 && b%2!=0)
		{
			if(b-a==2)
			{
				printf("YES\n");
				continue;
			}
		}
		if(a%2!=0 && b%2==0)
		{
			if(b-a==1)
			{	
				printf("YES\n");
				continue;
			}
		}
		printf("NO\n");
	}
	return 0; 
} 