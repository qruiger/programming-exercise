#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		string s;
		int a[10]={0};
		cin>>s;
		int n=s.length();
		for(int i=0;i<n;i++)
		{
			a[s[i]-'0']++;
		}
		if(a[6]==0 && a[7]==0 && a[8]==0 && a[9]==0)
		{
			printf("\n");
			continue;
		}
		int i,count,op;
		char c;
		/*six*/
		i=6;
		if(a[i])
		{	
			for(int j=5;j<10;j++)
			{
				if(a[j])
				{	
					if(i==j && a[j]==1)
						continue;
					op=(i*10)+j;
					c=char(op);
					printf("%c",c);
				}
			}
		}
		/*seven*/
		i=7;
		if(a[i])
		{	
			for(int j=0;j<10;j++)
			{
				if(a[j])
				{	
					if(i==j && a[j]==1)
						continue;
					op=(i*10)+j;
					c=char(op);
					printf("%c",c);
				}
			}
		}
		/*eight*/
		i=8;
		if(a[i])
		{	
			for(int j=0;j<10;j++)
			{
				if(a[j])
				{	
					if(i==j && a[j]==1)
						continue;
					op=(i*10)+j;
					c=char(op);
					printf("%c",c);
				}
			}
		}
		/*nine*/
		if(a[9] && a[0])
		{	
			op=(9*10);
			c=char(op);
			printf("%c",op);
		}
		printf("\n");
	}
	return 0; 
}