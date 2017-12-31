#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int t,t1,r,c;
	char s[1006][1006]={'\0'};
	scanf("%d",&t);
	while(t--)
	{
		int flag=0,i,j;
		scanf("%d %d",&r,&c);
		for(i=0;i<r;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i<r-1)
				{	
					if(s[i][j]=='B' && s[i+1][j]=='A')
					{
						flag=1;
						break;
					}
				}
				if(s[i][j]=='W')
				{	
					if(j==0 || j==c-1)
					{
						flag=1;
						break;	
					}
					if(s[i][j+1]=='A' || s[i][j-1]=='A')
					{
						flag=1;
						break;
					}
					if(i<r-1 && s[i+1][j]=='A')
					{
						flag=1;
						break;
					}
					if(i>0 && s[i-1][j]=='B')
					{
						flag=1;
						break;
					}
				}
			}
			if(flag)
				break;
		}
		if(flag)
		{
			printf("no\n");
		}
		else
			printf("yes\n");
	}
	return 0; 
}