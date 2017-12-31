#include<stdio.h>
#include<string.h>
int main()
{
	int c,j,T,i;
	char x[100040],y[100040];
	scanf("%d",&T);
	while(T--)
	{
	 	scanf("%s%s",x,y);
	 	j=strlen(x);
		for(i=0;i<j;i++)
		{
			if(x[i]=='W' && y[i]=='W')
				printf("B");
			else if(x[i]=='B' && y[i]=='B')
				printf("W");
			else
				printf("B");
		}
		printf("\n");
	}
	return 0;
}
