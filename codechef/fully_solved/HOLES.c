#include<stdio.h>
#include<string.h>
int main()
{
	int T,n,l,i;
	char a[10001];
	scanf("%d",&T);
	while(T--)
	{
		int h=0;
		scanf("%s",a);
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]=='A' || a[i]=='D' || a[i]=='P' || a[i]=='Q' || a[i]=='O' || a[i]=='R')
				h+=1;
			if(a[i]=='B')
				h+=2;
		}
		printf("%d\n",h);
	}
}
