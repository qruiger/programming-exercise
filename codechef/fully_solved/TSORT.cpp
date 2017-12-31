#include<cstdio>
#include<climits>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL int long long
int main()
{
	LL n,i;
	scanf("%lld",&n);
	LL a[n];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
		printf("%lld\n",a[i]);
 	return 0; 
}