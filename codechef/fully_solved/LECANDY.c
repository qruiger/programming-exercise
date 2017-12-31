#include<stdio.h>
int main()
{
	long long int T,i,n,a[10001],c,sum;
	scanf("%lld",&T);
	while(T--)
	{
		sum=0;
		scanf("%lld %lld",&n,&c);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
			sum+=a[i];
		if(sum>c)
			printf("No\n");
		if(sum<=c)
			printf("Yes\n");
	}
	return 0;
} 
