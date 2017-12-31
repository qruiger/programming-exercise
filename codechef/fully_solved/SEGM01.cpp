#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
char s[100005],s1[100005];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",s);
		LL len=strlen(s);
		strcpy(s1,s);
		sort(s1,s1+len);
		LL count=1,none=0;
		if(s1[0]=='0')
			none++;
		for(LL i=len-1;i>0;i--)
		{
			if( (s1[i]=='1' && s1[i-1]=='1') || (s1[i]=='1' && s1[i-1]=='1') )
			{
				count++;
			}
			if(s1[i]=='0')
			{
				none++;
			}
		}
		if(none==len)
		{
			printf("NO\n");
			continue;
		}
		if(count==1 && none==len-1)
		{
			printf("YES\n");
			continue;
		}
		LL count1=1;
		for(LL i=0;i<len-1;)
		{
			if(i<len-1 && s[i]=='1' && s[i+1]=='1')
			{	
				while(i<len-1 && s[i]=='1' && s[i+1]=='1')
				{
					count1++;
					i++;
				}
			}
			else
				i++;
		}
		if(count1==count)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0; 
} 
