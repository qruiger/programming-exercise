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
		LL n,i,ans=0,maxval;
		scanf("%lld",&n);
		LL freq[100005]={0};
		for(LL i=1;i<=n;i++)
		{	
			scanf("%lld",&a[i]);
			b[i]=a[i];
			maxval=maxval<a[i]?a[i]:maxval;
			freq[a[i]]++;
		}
		if(n==1)
		{
			printf("0\n");
			printf("%lld\n",a[1]);
			continue;
		}
		int fst=0;
		for(LL i=1;i<=maxval;i++)
		{
			if(freq[i]>1)
			{
				fst=1;
				break;
			}
		}	
		if(!fst)
		{
			printf("%lld\n",n);
			for(LL i=2;i<=n;i++)
				printf("%lld ",a[i]);
			printf("%lld\n",a[1]);
		}
		else
		{
			for(LL i=1;i<=n;i++)
			{
				if(a[i]==b[i])
				{	
					for(LL j=1;j<=n;j++)
					{
						if(a[i]!=b[j] && a[j]!=b[i])
						{
							swap(b[i],b[j]);
						}
						/*for(LL x=1;x<=n;x++)
							printf("%lld ",b[x]);
						printf("\n");*/	
					}
				}
			}
			for(LL i=1;i<=n;i++)
			{
				if(a[i]!=b[i])
					ans++;
			}
			printf("%lld\n",ans);
			for(LL i=1;i<=n;i++)
				printf("%lld ",b[i]);
			printf("\n");
		}
	}
	return 0; 
} 