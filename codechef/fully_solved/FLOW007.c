#include<stdio.h>
int main()
{
	int T,i;
	long int n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%ld",&n);
		int r=0,rev=0;
		while(n>0)
		{
			r=n%10;
			rev=(rev*10)+r;
			n/=10; 
		}
		printf("%d\n",rev);
	}
	return 0;
}
