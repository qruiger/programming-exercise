#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 505
LL a[lim][lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i,one=0,j,zero,k=0,temp[lim]={0},sum=0,flag=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{	
			for(j=1;j<=n;j++)
			{	
				scanf("%lld",&a[i][j]);
				if(a[i][j]==1)
					one++;
			}
		}
		if(one==0 || one==n)
		{
			printf("0\n");
			continue;
		}
		else if(one==(n*n))
		{
			printf("%lld\n",n-1);
			continue;
		}
		zero=abs(one-(n*n));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				temp[abs(i-j)]++;
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%lld ",temp[i]);
		}
		printf("\n");
		for(i=0;i<n;i++)
		{
			sum=0,flag=0;
			for(j=i+1;j<n;j++)
			{
				sum+=temp[j];
			}
			if(sum<=zero)
			{
				printf("%lld\n",i);
				flag=1;
				break;
			}
			if(flag)
				break;
		}
	}
	return 0; 
} 