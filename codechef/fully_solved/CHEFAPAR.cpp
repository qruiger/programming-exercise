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
		LL n,i,a[100005],one=0,zero=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{	
			scanf("%lld",&a[i]);
			if(a[i]==1 && zero>0)
				one++;
			if(a[i]==0)
				zero++;
		}
		if(zero>0)
		{	
			one=one*100;
			zero=zero*1100;
			printf("%lld\n",one+zero);
		}
		else
			printf("0\n");
	}
	return 0;
}	