#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL n,q,min_val,max_val,a[lim],b[lim];
LL query(LL left,LL right)
{
	LL mmax,ans=0,ind;
	for(LL i=left;i<=right;i++)
	{
		ind=1;
		for(LL j=i;j<=right;j++)
		{
			ind=1;
			for(LL k=i;k<=j;k++)
			{	
				b[ind]=a[k];
				ind++;
			}
			ind--;
			mmax=LLONG_MIN;
			for(LL x=1;x<=ind;x++)
			{
				if(b[x]>=mmax)
					mmax=b[x];
			}
			if(mmax>=min_val && mmax<=max_val)
				ans++;
		}
	}
	return ans;
}
int main()
{
	scanf("%lld %lld %lld %lld",&n,&q,&min_val,&max_val);
	memset(a,n+5,0);
	while(q--)
	{
		int type;
		LL left,right,ans=0;
		scanf("%d %lld %lld",&type,&left,&right);
		{
			if(type==1)
				a[left]=right;
			if(type==2)
				printf("%lld\n",query(left,right));
		}
	}	
	return 0; 
} 