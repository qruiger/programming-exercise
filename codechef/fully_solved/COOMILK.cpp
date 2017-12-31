#include <bits/stdc++.h>
using namespace std;
#define lim 100005
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		char s[n+5][8];
		char s1[]="cookie";
		char s2[]="milk";
		for(int i=1;i<=n;i++)
		{	
			scanf("%s",s[i]);
		}
		int len;
		if(!strcmp(s[n],s1))
		{
			printf("NO\n");
			continue;
		}
		int flag=0;
		for(int i=1;i<n;i++)
		{
			if( (!strcmp(s[i],s1)) && (strcmp(s[i+1],s2)) )
			{
				flag=1;
				break;
			}	
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0; 
}