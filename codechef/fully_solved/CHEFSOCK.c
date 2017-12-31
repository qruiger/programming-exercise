#include<stdio.h>
int main()
{
	long long int j,s,m,c;
	scanf("%lld %lld %lld",&j,&s,&m);
    m-=j;
    c=m/s;
    if(c%2==0)
    	printf("Lucky Chef");
    else
    	printf("Unlucky Chef");
	return 0;
} 