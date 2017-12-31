#include <bits/stdc++.h>
using namespace std;
#define LL long long int
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL N,i,k,ans=0,a=0,b=0;
		scanf("%lld %lld",&N,&k);
		char s[100005];
		scanf("%s",s);
		for(i=0;i<N;i++)
		{
			if(s[i]=='a')
				a++;
			if(s[i]=='b')
			{	
				ans+=a;
				b++;
			}
		}
		ans=ans*k;
		ans+=(k*(k-1)/2)*a*b;
		printf("%lld\n",ans);	
	}
	return 0; 
}