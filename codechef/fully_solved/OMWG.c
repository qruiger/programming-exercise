#include<stdio.h>
#define LL long long int
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,n,m;
		scanf("%d %d",&n,&m);
		a=2*m*n-m-n;
		printf("%d\n",a);
	}  
}
