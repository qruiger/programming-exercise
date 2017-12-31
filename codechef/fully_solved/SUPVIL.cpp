#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL int long long
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i,flag,good=1,bad=1,j,k=0;
		scanf("%lld",&n);
		char a[100005][20]={'\0'};
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		for(i=0;i<n;i++)
		{
			LL len=strlen(a[i]);
			flag=0;
			j=len-3;
			if(a[i][j]=='m')
			{
				if(a[i][j+1]=='a')
				{
					if(a[i][j+2]=='n')
						flag=1;
				}
			}
			if(flag==1)
				good++;
			else
				bad++;
			if((good-bad)>=2)
			{
				printf("superheroes\n");
				k=1;
				break;
			}
			else if((bad-good)>=3)
			{
				printf("villains\n");
				k=1;
				break;
			}
		}
		if(k==1)
			continue;
		else
			printf("draw\n");
	}
	return 0; 
} 