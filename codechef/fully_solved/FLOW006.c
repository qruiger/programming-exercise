#include<stdio.h>
int main()
{
	int T,N,r,n,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		n=N;
		sum=0;
		while(n>0)
		{ 
			r=n%10;
			n=n/10;
			sum+=r;
		}
		printf("%d\n",sum);
	}
}
