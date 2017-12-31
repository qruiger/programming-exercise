#include<cstdio>
#include<algorithm>
using namespace std;
#define LL int long long
int main()
{ 	
	LL n,i,m=0,n1;
	scanf("%lld",&n);
	LL a[n];
	n1=n;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	for(i=0;i<n;i++)
		m=max((a[i]*n1--),m);
	printf("%lld\n",m);
	return 0; 
}
