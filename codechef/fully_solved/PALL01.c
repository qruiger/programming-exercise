#include<stdio.h>
int main()
{
	int T,r,n,rev,temp;
	scanf("%d",&T);
	while(T--)
	{
		rev=0;
		scanf("%d",&n);
		temp=n;
		while(n>0)
		{
			r=n%10;
			rev=(rev*10)+r;
			n=n/10;
		}
        	if(rev==temp)
			printf("wins\n");
        	else
	        	printf("losses\n");
     	}
	return 0;
}
