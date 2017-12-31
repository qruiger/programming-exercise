#include<stdio.h>
int main()
{
	int T,a,b,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		if(a>b)
			r=a;
		else
			r=b;
		printf("%d %d\n",r,a+b);
	}
	return 0;
}