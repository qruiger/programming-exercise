#include<stdio.h>
#include<math.h>
int main()
{
	int T,n,s;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		s=sqrt(n);
		printf("%d\n",s);
	}
	return 0;
}