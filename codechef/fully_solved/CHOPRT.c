#include<stdio.h>
int main()
{
	int T;
	long long int a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
        	if(a<b)
        		printf("<\n");
        	if(a>b)
        		printf(">\n");
		if(a==b)
			printf("=\n");
	}
	return 0;
}
