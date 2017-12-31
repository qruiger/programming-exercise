#include <bits/stdc++.h>
using namespace std;
void output(int op[])
{
	for(int i=1;i<=7;i++)
		printf("%d ",op[i]);
	printf("\n");
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int w,start=0,op[10];
		for(int i=1;i<=7;i++)
			op[i]=4;
		char s[10];
		scanf("%d",&w);
		scanf("%s",s);
		if(strcmp(s,"mon")==0)
			start=1;
		if(strcmp(s,"tues")==0)
			start=2;
		if(strcmp(s,"wed")==0)
			start=3;
		if(strcmp(s,"thurs")==0)
			start=4;
		if(strcmp(s,"fri")==0)
			start=5;
		if(strcmp(s,"sat")==0)
			start=6;
		if(strcmp(s,"sun")==0)
			start=7;
		if(w==28)
		{
			output(op);
		}
		if(w==29)
		{
			op[start]++;
			output(op);
		}
		if(w==30)
		{
			op[start]++;
			if(start==7)
				op[1]++;
			else
				op[start+1]++;
			output(op);
		}
		if(w==31)
		{
			op[start]++;
			if(start<=5)
			{
				op[start+1]++;
				op[start+2]++;
			}	
			if(start==6)
			{
				op[7]++;
				op[1]++;
			}
			if(start==7)
			{
				op[1]++;
				op[2]++;
			}
			output(op);
		}
	}
	return 0; 
}