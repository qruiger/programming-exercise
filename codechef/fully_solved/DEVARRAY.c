#include<stdio.h>
#include<limits.h>
int main()
{
	long int n,q,i,a,b,max=0,min=INT_MAX;
	scanf("%ld %ld",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&a);
		if(max<a)
			max=a;
		if(min>a)
			min=a;
	}
	for(i=0;i<q;i++)
	{
	   scanf("%ld",&b);
	   if(b>=min && b<=max)
	   	printf("Yes\n");
	   else
	   	printf("No\n");
	}

	return 0;
} 