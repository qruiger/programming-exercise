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
		LL i,n,max=0,j,count=0,flag=0;
		scanf("%lld",&n);
		LL a[105],b[505]={0};
		for(i=0;i<n;i++)
		{	
			scanf("%lld",&a[i]);
			max=max<a[i]?a[i]:max;
			b[a[i]]++;
		}
		for(i=0,j=1;i<n-1;i++,j++)
		{
			if(a[j]>a[i])
			{
				if(a[j]==(a[i]+1))	
				count++;
			}
		}
		for(i=1;i<=max;i++)
		{
			if(b[i]==0 || b[i]>1)
				flag=1;
		}
		if(count==n-1 || flag==1)
		{
			printf("no\n");
		}
		else
			printf("yes\n");
	}
	return 0; 
} 