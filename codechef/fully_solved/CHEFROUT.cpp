#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
char s[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",s);
		LL len=strlen(s);
		int c =0;
		for(LL i=0;i<len-1;i++)
		{
			if(s[i]>s[i+1])
			{
				printf("no\n");
				c=1;
				break;
			}
		}
		if(!c)
			printf("yes\n");
	}
	return 0; 
} 