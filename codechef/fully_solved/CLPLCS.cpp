#include <bits/stdc++.h>
using namespace std;
#define LL int long long
int main()
{
	char s[100][100],last,first;
	int n,i,count,search_further,ans=0,j,k,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for(i=0;i<n;i++)
	{
		first=s[i][0];
		last=s[i][strlen(s[i])-1];
		printf("ind=%d first=%c last=%c\n",i,first,last);
		count=0;
		int check[100]={0};
		check[i]=1;
		while(1)
		{
			search_further=0;
			temp=-1;
			for(j=0;j<n;j++)
			{
				if(check[j]==0)
				{	
					if(s[j][0]==last)
					{
						temp=max(temp,j);
						search_further=1;
					}
				}
			}
			if(search_further==0)
			{	
				printf("\n");
				break;
			}
			count++;
			last=s[temp][strlen(s[temp])-1];
			printf("ind=%d first=%c last=%c\n",temp,s[temp][0],last);
			check[temp]=1;
		}
		ans=max(count+1,ans);
	}
	printf("%d\n",ans);
	return 0; 
} 