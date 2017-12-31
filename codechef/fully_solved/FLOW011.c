#include<stdio.h>
int main()
{
	int T,i;
	long long int s;
	float gs;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&s);
		if(s<1500 && s>=0)
			gs=(float)s+(0.1*s)+(0.9*s);
		if(s>=1500)
			gs=(float)s+500+(0.98*s);
		printf("%g\n",gs);
	}       
	return 0;
}