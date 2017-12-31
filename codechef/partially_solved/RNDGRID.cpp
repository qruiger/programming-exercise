#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL L,n,row,col,ind,val;
char s[5005],v[1005][1005];
void follow_command()
{
	LL j;
	int flag;
	for(j=0;j<L;j++)
	{
		flag=0;
		if(s[j]=='D' && row+1<n && v[row+1][col]!='#')
		{	
			flag=1;
			val++;row++;
		}
		if(s[j]=='U' && row-1>=0 && v[row-1][col]!='#')
		{	
			flag=1;
			val++;row--;
		}
		if(s[j]=='R' && col+1<n && v[row][col+1]!='#')
		{	
			flag=1;
			val++;col++;
		}
		if(s[j]=='L' && col-1>=0 && v[row][col-1]!='#')
		{	
			flag=1;
			val++;col--;
		}
		if(flag==0)
			break;
	}
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL j,i,op=0;
		ind=0;
		scanf("%lld %lld",&L,&n);
		scanf("%s",s);
		for(i=0;i<n;i++)
			scanf("%s",v[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(v[i][j]=='.')
				{
					val=0;
					row=i;
					col=j;
					follow_command();
					if(op==0)
					{
						op=val;
					}
					else
						op^=val;
				}
			}
		}
		printf("%lld\n",op);
	}	
	return 0; 
}  