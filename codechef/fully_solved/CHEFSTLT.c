#include<stdio.h>
#include<string.h>
int main()
{
	int T,count,max,l1,i,min;
	char s1[102],s2[102];
	scanf("%d",&T);
	while(T--)
	{
		count=0;
		max=0,min=0;
		scanf("%s",s1);
		scanf("%s",s2);
		l1=strlen(s1);
		for(i=0;i<l1;i++)
		{
			if(s1[i]!='?' && s2[i]!='?')
			{
				if(s1[i]!=s2[i])
					count++;
			}
		}
		for(i=0;i<l1;i++)
		{
			if(s1[i]=='?')
			{ 
			  if(s2[i]=='?')
              	max+=1;
            }
			if(s1[i]!=s2[i])
			{
				if(s2[i]=='?' || s1[i]=='?')
				max+=1;
			}
		}
		printf("%d %d\n",count+min,count+max);	
	}
	return 0;
}