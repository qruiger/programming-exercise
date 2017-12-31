#include <bits/stdc++.h>
using namespace std;
#define LL int long long
int main()
{
	LL n,x;
	scanf("%lld",&n);
	scanf("%lld",&x);
	LL ans=n%6;
	LL a[6][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
	printf("%lld\n",a[ans][x]);
	return 0; 
} 
