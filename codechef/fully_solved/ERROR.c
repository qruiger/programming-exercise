#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		 char s[100001];
		 int i,l,g=0,g1=0;
		 scanf("%s",s);
		 l=strlen(s);
		 for(i=0;i<l;i++)
		 {
			if(s[i]=='0')
			{
				if(s[i+1]=='1' && s[i+2]=='0')
					g++;
			}
			if(s[i]=='1')
			{
				if(s[i+1]=='0' && s[i+2]=='1')
					g1++;
			}
		 }
		 if(g>0 || g1>0)
			printf("Good\n");
		 else
			printf("Bad\n");
    	}
	return 0;
} 
