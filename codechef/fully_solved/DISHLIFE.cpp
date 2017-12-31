#include <bits/stdc++.h>
using namespace std;
#define LL int long
#define lim 100005
int main()
{
	LL t; 
	scanf("%ld",&t);
	while(t--)
	{
		LL n,k,i,j,reset,some=0,all=0,v,u,freq[lim]={0};
		scanf("%ld %ld",&n,&k);
		for(j=1;j<=n;j++)
		{
			scanf("%ld",&u);
			for(i=1;i<=u;i++)
			{	
				scanf("%ld",&v);
				if(some==0)
					freq[v]++;
			}
			if(some==0)
			{	
				reset=0;
				for(i=1;i<=k;i++)
				{
					if(freq[i]==0)
					{
						reset=1;
						break;
					}
				}
				if(reset==0 && j<n)
				{
					some++;
				}
				if(some)
					continue;
			}
			if(some==0 && reset==0 && j==n)
			{
				all++;
			}
		}
		if(some)
			printf("some\n");
		else if(all)
			printf("all\n");
		else
			printf("sad\n");
	}
	return 0; 
}  