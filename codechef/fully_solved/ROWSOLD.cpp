#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL ct,len,one[lim];
char s[lim];
int chk()
{
	LL i,c=1;
	i=len-ct;
	for(;i<len-1;i++)
	{
		if(s[i]=='1' && s[i+1]=='1')
		{
			c++;
		}
		else
			return 1;
	}
	if(c==ct)
		return 0;
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		LL j=0,o=0,k,ans=0,i=0,ind,jump;
		ct=0;
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]=='1')
			{
				one[j++]=++o;
				ct++;
			}
			else
			{
				one[j++]=o;	
			}
		}
		if(chk()==0)
		{
			printf("0\n");
			continue;
		}	
		int flag=1;
		for(i=0;i<len-1;)
		{
			jump=0;
			if(s[i]=='1' && s[i+1]=='0')
			{
				k=i;
				ind=i+1;
				ans+=one[k];
				jump++;
				while(ind<len && s[ind]=='0')
				{
					ans+=one[k];
					ind++;
					jump++;
				}
				i+=jump;
			}
			else
				i++;
		}
		printf("%lld\n",ans);
	}
	return 0; 
}