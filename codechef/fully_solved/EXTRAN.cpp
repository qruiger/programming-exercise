#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000005
LL a[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		if(abs(a[1]-a[0])>1)
		{	
			printf("%lld\n",a[0]);
			continue;
		}
		if(abs(a[n-1]-a[n-2])>1)
		{	
			printf("%lld\n",a[n-1]);
			continue;
		}
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
			{
				printf("%lld\n",a[i]);
				break;
			}
		}
	}
	return 0; 
} 