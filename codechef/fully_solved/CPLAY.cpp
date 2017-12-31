#include <bits/stdc++.h>
using namespace std;
char a[25];
string s;
int main()
{
	while(scanf("%s",a+1)==1) 
	{
		int ct=0,st=0,cg=0,sg=0,tma=0,tmb=0,i;
		for(i=1;i<=20;i++)
		{
			if(i%2!=0)
			{
				ct++;
				if(a[i]=='1')
					cg++;
			}
			if(i%2==0)
			{
				st++;
				if(a[i]=='1')
					sg++;
			}	
			if(i<=10 && i>=6)
			{
				if((5-ct)+cg<sg)
				{
					tmb=1;
					break;
				}
				if((5-st)+sg<cg)
				{
					tma=1;
					break;
				}
			}
			if(i>10 && i%2==0)
			{
				if(cg<sg)
				{
					tmb=1;
					break;
				}
				if(sg<cg)
				{
					tma=1;
					break;
				}
			}
		}
		if(tma)
		{
			printf("TEAM-A %d\n",i);
			continue;
		}
		if(tmb)
		{
			printf("TEAM-B %d\n",i);
			continue;
		}
		printf("TIE\n");
	}
	return 0; 
}
