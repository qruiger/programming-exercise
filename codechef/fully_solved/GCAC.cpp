/*input
1
5 6
5000 10000 3000 20 100
10000 2
800 2
600 1
10 8
1000 9
2000 10
111111
100000
000000
000001
100100
*/
#include <bits/stdc++.h>
using namespace std;
#define LL int long long
LL n,m,msal[1005],osal[1005],mjo[1005],qual[1005][1005];
char q[1005][1005];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		for(LL i=1;i<=n;i++)
		{
			scanf("%lld",&msal[i]);
		}
		for(LL i=1;i<=m;i++)
		{
			scanf("%lld %lld",&osal[i],&mjo[i]);
		}
		for(LL i=1;i<=n;i++)
		{scanf("%s",q[i]+1);}
		for(LL i=1;i<=n;i++)
		{	for(LL j=1;j<=m;j++)
				{qual[i][j]=q[i][j]-'0';}
		}
		LL mn,mx=-1,temp[1005]={0},k=1,cd=0,ts=0,nhc=0,var;
		for(LL i=1;i<=n;i++)
		{
			k=1;
			mn=msal[i],mx=-1,var=0;
			for(LL j=1;j<=m;j++)
			{
				if(qual[i][j]==1 && mjo[j]>=1 && osal[j]>=mn)
				{
					if(mx<osal[j])
					{
						mx=osal[j];
						var=j;
					}	
				}
			}
			if(var!=0)
			{
				cd++;
				ts+=mx;
				temp[var]++;
				mjo[var]--;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(temp[i]==0)
			{
				nhc++;
			}
		}
		printf("%lld %lld %lld\n",cd,ts,nhc);
	}
	return 0; 
}