#include<stdio.h>
int main()
{
	int T,i,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n<10)
			printf("What an obedient servant you are!\n");
		else
			printf("-1\n"); 		
	}
	return 0;
}
