#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
char c[lim];
int main()
{
	LL n,i;
	scanf("%lld",&n);
	LL freq[11],freq1[11],s[n+1],m[n+1];
	memset(freq,0,sizeof(freq));
	memset(freq1,0,sizeof(freq1));
	scanf("%s",c+1);
	for(LL i=1;i<=n;i++)
		s[i]=c[i]-'0';
	scanf("%s",c+1);
	for(LL i=1;i<=n;i++)
	{
		m[i]=c[i]-'0';
		freq[m[i]]++;
		freq1[m[i]]++;
	}
	//mor lose min rounds i.e. min no. of flicks to moriarity
	LL ans=0;
	for(LL i=1;i<=n;i++)
	{	
		for(LL j=s[i];j<10;j++)
		{
			if(freq[j])
			{
				freq[j]--;
				ans++;
				break;
			}
		}			
	}
	//printf("%lld\n",ans);
	printf("%lld\n",n-ans);
	//mor win max round i.e. max no. of flicks to sherlock
	LL ans1=0;
	for(LL i=1;i<=n;i++)
	{
		for(LL j=s[i]+1;j<10;j++)
		{
			if(freq1[j])
			{
				freq1[j]--;
				ans1++;
				break;
			}
		}	
	}
	printf("%lld\n",ans1);
	return 0; 
}
