/*The problem definition doesn't say whether the squares are equal in dimension or not*/
#include<stdio.h>
int main()
{
	int T,l,n,m,a,b;
	scanf("%d",&T);
	while(T--)
	{		
		scanf("%d %d",&n,&m);
		a=n;
		b=m;
		while(a!=b)
		{
			a=a>b?a-b:a;
			b=b>a?b-a:b;
		}
		printf("%d\n",(n*m)/(a*a));
	}
	return 0;
} 