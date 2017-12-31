#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char s[51];
		int c[26]={0},sum=0,max=0,f,i;
		scanf("%s",s);
		int l=strlen(s);
		for(i=0;i<l;i++)
		{ 
			c[s[i]-97]++;
			f=c[s[i]-97];
			if(max<f)
				max=f;
		}
		for(i=0;i<26;i++)
			sum+=c[i];
		sum-=max;
		if(sum==max) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
 }
