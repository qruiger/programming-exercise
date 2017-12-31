#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL a[lim],L,R,n,q,i,k,ct,ans;
LL query()
{
	ct=1,ans=0;
	for(i=L;i<R;i++)
	{
		if(a[i]==a[i+1])
		{
			ct++;
			if(i==R-1 && ct>=k)
			{
				ans++;
			}
		}
		if(a[i]!=a[i+1])
		{
			if(k==1)
			{	
				ans++;
				ct=1;
				if(i==R-1)
					ans++;
				continue;
			}
			if(ct>=k)
			{
				ans++;
			}
			ct=1;
		}
	}
		return ans;
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&q);
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		while(q--)
		{
			scanf("%lld %lld %lld",&L,&R,&k);
			if(L==R)
			{
				printf("1\n");
				continue;
			}
			printf("%lld\n",query());
		}
	}
	return 0; 
}  
