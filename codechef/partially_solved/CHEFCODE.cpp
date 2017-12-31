#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL a[lim],b[lim];
bool check(LL tip, LL k)
{
	LL prod=1;
	for(LL i=0;i<tip;i++)
	{	
		prod*=b[i];
		if(prod>k)
			return true;
	}
	return false;
}
int main()
{
	LL k,n,i,j,ind,ans=0;
	scanf("%lld %lld",&n,&k);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	i=1;
	while(i<1<<n)
	{
		j=0,ind=0;
		while(j<n)
		{
			if((1<<j)&i) 
			{
				b[ind++]=a[j];
			}	
			j++;
		}
		if(check(ind,k)==true)
			ans++;
		i++;
	}
	printf("%lld\n",((1<<n)-1)-ans);
	return 0; 
} 
