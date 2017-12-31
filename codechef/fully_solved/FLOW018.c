#include<stdio.h>
int main()
{
	int T,i,n;
	scanf("%d",&T);
	while(T--)
	{
		int fact=1;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			fact*=i;
		printf("%d\n",fact);
	}
	return 0;
}