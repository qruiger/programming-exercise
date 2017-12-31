#include <bits/stdc++.h>
#define LL int long long
LL a[100005],one[100005];
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)	
	{
		LL n,center,ans=0,i,k=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{	
			scanf("%lld",&a[i]);
			if(a[i]==1)
			{
				one[k++]=i;
			}
		}
		center=round(1.0*k/2)-1;
		printf("center=%lld\n",center);
		for(i=0;i<k;i++)
		{
			printf("%lld ",one[i]);
		}
		printf("\n");
		for(i=0;i<k;i++)
		{
			printf("%lld ",i);
		}
		printf("\n");
		for(i=0;i<k;i++)
		{
			ans+=abs(one[center]-one[i])-abs(center-i);
			printf("ans=%lld\n",ans);
		}
		printf("swaps=%lld center_index=%lld\n",ans,one[center]);
	}	
	return 0; 
} 