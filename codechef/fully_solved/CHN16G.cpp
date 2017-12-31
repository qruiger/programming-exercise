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
		LL n,i,count=0;
		scanf("%lld",&n);
		LL a[105],b[105]={0};
		for(i=0;i<n;i++)
		{	
			scanf("%lld",&a[i]);
			b[a[i]]++;
		}
		for(i=1;i<=100;i++)
		{
			if(b[i]>1)
			{
				count+=b[i]-1;
			}
		}
		printf("%lld\n",count);
	}
	return 0; 
} 