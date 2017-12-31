#include <stdio.h>
#include <string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int L,n,i,count=0,aux[1001]={0};
		scanf("%d",&n);
		char s[1001]={'\0'};
		scanf("%s",s);
		L=strlen(s);
		if(s[0]=='1')
		{
			aux[1]=1;
		}
		if(s[L-1]=='1')
		{
			aux[L-2]=1;
		}
		for(i=1;i<=L-2;i++)
		{
			if(s[i]=='1')
			{
				aux[i-1]=1;aux[i+1]=1;
			}
		}
		for(i=0;i<L;i++)
		{
			if(aux[i]==0 && s[i]=='0')
				count++;
		}
		printf("%d\n",count);	
	}
	return 0; 
} 