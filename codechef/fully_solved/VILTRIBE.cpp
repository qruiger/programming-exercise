#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
char s[lim];
LL a[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",s);
		LL len=strlen(s);
		LL ans1=0,ans2=0,ind=0;
		for(LL i=0;i<len;i++)
		{
			if(s[i]=='A')
			{	
				ans1++;
				a[ind++]=i;
			}
			if(s[i]=='B')
			{	
				ans2++;
				a[ind++]=i;
			}
		}
		for(LL i=0;i<ind-1;i++)
		{
			if(s[a[i]]==s[a[i+1]])
			{
				if(s[a[i]]=='A')
					ans1+=abs(a[i+1]-a[i])-1;
				if(s[a[i]]=='B')
					ans2+=abs(a[i+1]-a[i])-1;
			}
		}
		printf("%lld %lld\n",ans1,ans2);	
	}
	return 0; 
}