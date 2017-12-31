#include<stdio.h>
int main()
{
	long long int abs,n,i,e=0,o=0;
	scanf("%lld",&n);
	long long int a[n];
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
			e++;
		else
			o++;
	}
	if(e==o)
		printf("0");
	else
	{	
		abs=e>o?e-o:o-e;
		printf("%lld",abs);
	}
	return 0;
} 
