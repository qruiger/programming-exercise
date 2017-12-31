#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,c=0,d=0,l1,l2;	
		char a[11],b[11];
		scanf("%s %s",a,b);
		l1=strlen(a);
		l2=strlen(a);
		if(l1!=l2)
			printf("No\n");
		else
		{	
			for(i=0;i<l1;i++)
			{
				if(a[i]!='?' && b[i]!='?')
				{
					c++;
					if(a[i]==b[i])
						d++;
				}	
			}
			if(c==d)
				printf("Yes\n");
			else
				printf("No\n");
		}	
	}
	return 0;
} 
