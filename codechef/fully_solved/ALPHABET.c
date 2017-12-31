#include<stdio.h>
#include<string.h>
int main()
{
	char s[27],w[13];
	int j,n,i,count=0,flag=0,sl,wl;
	scanf("%s",s);
	sl=strlen(s);
	scanf("%d",&n);
	while(n--)
	{
		flag=0;	
		scanf("%s",w);
		wl=strlen(w);
		for(i=0;i<wl;i++)
		{
			count=0;
			for(j=0;j<sl;j++)
			{
				if(w[i]==s[j])
				{
					count++;
					break;
				}
			}
			if(count==0)
			{
				flag=1;	
				break;
			}	
		}
		if(flag==0)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;   		 
}
