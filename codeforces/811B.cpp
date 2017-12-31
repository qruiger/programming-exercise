#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL p[lim];
int main()
{
	LL n,m;
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	while(m--)
	{
		LL L,R,x,ans=0;
		scanf("%lld %lld %lld",&L,&R,&x);
		for(LL i=L;i<=R;i++)
		{
			if(p[i]<p[x])
				ans++;
		}
		//cout<<"ans="<<ans<<endl<<"x-L="<<x-L<<endl;
		if(ans==abs(x-L))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0; 
}
