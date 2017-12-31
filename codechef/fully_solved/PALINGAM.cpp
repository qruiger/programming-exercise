#include <bits/stdc++.h>
using namespace std;
int len;
void count(int *scount,int *tcount,char *s,char *t)
{
	for(int i=0;i<len;i++)
	{
		scount[s[i]-96]++;
		tcount[t[i]-96]++; 
	}
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		char s[515]={'\0'},t[515]={'\0'};
		int scount[27]={0},tcount[27]={0};
		scanf("%s",s);
		scanf("%s",t);
		len=strlen(s);
		sort(s,s+len);
		sort(t,t+len);
		if(len==1)
		{
			printf("B\n");
			continue;
		}
		count(scount,tcount,s,t);
        	int flag=0,x1=0,x2=0,ct=0;
        	for(int i=1;i<27;i++)
        	{
            		if(tcount[i]!=0)
            		{
                		ct++;
            		}
        	}
		for(int i=1;i<27;i++)
		{
			if(scount[i]>=2 && tcount[i]==0)
			{
				flag=1;
				break;
			}
            		if(tcount[i]!=0 && scount[i]!=0)
			{
				x1++;
			}
			if(scount[i]!=0 && tcount[i]==0)
			{
				x2++;
			}

		}
		if(flag==1 || (x1==ct && x2==1))
		{
			printf("A\n");
			continue;
		}
		printf("B\n");
	}
	return 0; 
} 
