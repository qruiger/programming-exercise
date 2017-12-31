#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000000
#define M 1000000007
LL cs[lim],cmd[lim],a[lim];
struct command
{LL type,left,right;};
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL n,m;
		scanf("%lld %lld",&n,&m);
		command cd[m+2];
		for(LL i=0;i<=max(n,m)+2;i++)
		{cs[i]=0,cmd[i]=1,a[i]=0;};	 
		for(LL i=1;i<=m;i++)
			scanf("%lld %lld %lld",&cd[i].type,&cd[i].left,&cd[i].right);
		LL csum=0;
		for(LL i=m;i>=1;i--)
		{
			if(cd[i].type==2)
			{
				csum=((csum+cs[i])%M+M)%M;
				cmd[i]=((cmd[i]+csum)%M+M)%M;
				cs[cd[i].left-1]=((cs[cd[i].left-1]-cmd[i])%M+M)%M;
				cs[cd[i].right]=((cs[cd[i].right]+cmd[i])%M+M)%M;
			}
			else
			{
				csum=((csum+cs[i])%M+M)%M;
				cmd[i]=((cmd[i]+csum)%M+M)%M;
			}
		}
		for(LL i=1;i<=m;i++)
		{
			if(cd[i].type==1)
			{
				a[cd[i].left]=((a[cd[i].left]+cmd[i])%M+M)%M;
				a[cd[i].right+1]=((a[cd[i].right+1]-cmd[i])%M+M)%M;
			}
		}
		/*printf("cs\n");
		for(LL i=0;i<=m;i++)
		{
			printf("%lld ",cs[i]);
		}
		printf("\n");
		printf("cmd\n");
		for(LL i=0;i<=m;i++)
		{
			printf("%lld ",cmd[i]);
		}
		printf("\n");
		printf("a\n");
		for(LL i=0;i<=n;i++)
		{
			printf("%lld ",a[i]);
		}
		printf("\n");*/
		LL val=0;
		for(LL i=1;i<=n;i++)
		{
			val=((val+a[i])%M+M)%M;
			printf("%lld ",val);
		}		
		printf("\n");
	}
	return 0;
}	 