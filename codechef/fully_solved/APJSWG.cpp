#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL int long long
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i,k=1,ans=0,flag=0,j;
		scanf("%lld",&n);
		LL a[100005];LL b[100005]={0};
		for(i=1;i<=n;i++)
		{	
			scanf("%lld",&a[i]);
			if(a[i]>i)
				b[k]=a[i]-i;
			k++;
		}
		for(i=1;i<=n-1;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]>a[j])	
					ans++;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(b[i]>2)
				flag=1;
		}
		if(flag==1)
			printf("Not Allowed\n");
		else
			printf("%lld\n",ans);
	}
	return 0; 
}  