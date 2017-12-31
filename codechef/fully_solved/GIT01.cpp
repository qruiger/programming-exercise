#include <bits/stdc++.h>
using namespace std;
char s[105][105];
int n,m,val1,val2,x;
int update(int i,int j)
{
	if(s[i][j]=='R')
		val1+=5;
	else
		val2+=3;
}
int check1()
{
	val1=0,val2=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0)
			x=1;
		else
			x=0;
		for(int j=1;j<=m;j++)
		{
			if(x==1)
			{
				if((j%2==0 && s[i][j]=='G') || (j%2!=0 && s[i][j]=='R'))
					continue;
				else
					update(i,j);
			}
			if(x==0)
			{
				if((j%2!=0 && s[i][j]=='G') || (j%2==0 && s[i][j]=='R'))
					continue;
				else
					update(i,j);
			}
		}
	}
	return val1+val2;
}
int check2()
{
	val1=0,val2=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
			x=1;
		else
			x=0;
		for(int j=1;j<=m;j++)
		{
			if(x==1)
			{
				if((j%2==0 && s[i][j]=='G') || (j%2!=0 && s[i][j]=='R'))
					continue;
				else
					update(i,j);
			}
			if(x==0)
			{
				if((j%2!=0 && s[i][j]=='G') || (j%2==0 && s[i][j]=='R'))
					continue;
				else
					update(i,j);
			}
		}
	}
	return val1+val2;
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		printf("%d\n",min(check1(),check2()));
	}	
	return 0; 
} 
