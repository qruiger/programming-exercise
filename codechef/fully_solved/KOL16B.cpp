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
	LL t,cs;
	scanf("%lld",&t);
	cs=1;
	while(t--)
	{
		LL n,i;
		scanf("%lld",&n);
		LL a[100005],b[100005];
		for(i=0;i<n;i++)
		{	
			LL x,y,e,y1;
			scanf("%lld",&e);
			b[i]=(LL)(e/65536);
			y1 = b[i]<<(1<<(1<<(1<<1)));
			a[i]=abs(e-y1);
		}
		printf("Case %lld:\n",cs++);
		for(i=0;i<n;i++)
			printf("%lld ",a[i]);
		printf("\n");
		for(i=0;i<n;i++)
			printf("%lld ",b[i]);
		printf("\n");
	}
	return 0; 
} 