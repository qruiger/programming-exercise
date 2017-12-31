#include<stdio.h>
int main()
{
	long int T;
	unsigned long long int n,j;
	scanf("%ld",&T);
	while(T--)
	{
		scanf("%llu",&n);
		if(n%2==0)
		{
			if(n==2)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
			printf("NO\n");	
	}
	return 0;
}  
