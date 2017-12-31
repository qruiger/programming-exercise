#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL a[15];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL L,R,n,i,dis=0,j,r,zero=0;
		scanf("%lld %lld",&L,&R);
		for(i=0;i<10;i++)
		{	
			scanf("%lld",&a[i]);
			if(a[i]==0)zero++;
		}
		if(zero==10)
		{
			printf("0\n");
			continue;
		}
		for(i=L;i<=R;i++)
		{
			LL check[11]={0};
			n=i;
			while(n>0)
			{
				r=n%10;
				check[r]++;
				n=n/10;
			}
			for(j=0;j<10;j++)
			{
				if(check[j]==a[j])
				{
					dis++;
					break;
				}
			}
		}
		printf("%lld\n",((R-L+1)-dis));
	}
	return 0; 
}  
