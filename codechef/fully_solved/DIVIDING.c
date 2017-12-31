#include<stdio.h>
int main()
{
	long int n,i,sum=0,a[100000],c=0;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{	
		scanf("%ld",&a[i]);
		sum+=a[i];
	}
	for(i=1;i<=n;i++)
		c+=i;
	if(sum==c)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
} 
