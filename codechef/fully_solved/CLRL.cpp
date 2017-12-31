#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 2000005
LL a[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,r,left=0,right=0,flag=0;
		scanf("%lld %lld",&n,&r);
		for(LL i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(LL i=1;i<=n;i++)
		{
			if(r<a[i])  //go left
			{
				if(left==0)
				{	
					left=a[i];
					continue;
				}	
				if(a[i]>left)
				{
					flag=1;
					break;
				}
				if(a[i]<left)
					left=a[i];
			}
			if(r>a[i])	//go right
			{
				if(right==0)
				{	
					right=a[i];
					continue;
				}
				if(a[i]<right)
				{
					flag=1;
					break;
				}
				if(a[i]>right)
					right=a[i];
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0; 
}