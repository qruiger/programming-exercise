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
		LL n,count=0,i;
		scanf("%lld",&n);
		LL a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n-1;i++)
		{
			if(abs(a[i]-a[i+1])>1)
				count++;
		}
		if(count==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0; 
} 