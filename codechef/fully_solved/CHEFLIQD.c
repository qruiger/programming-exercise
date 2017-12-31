#include<stdio.h>
#define LL long long int
int main()
{
	LL T;
	scanf("%lld",&T);
	while(T--)
	{
		LL n,m,k,i,p[10001],v[10001],c[10001],p1,j=0;
		scanf("%lld %lld %lld",&n,&m,&k);
        for(i=0;i<k;i++)
        scanf("%lld",&c[i]);	
        for(i=0;i<n;i++)
       { 	
        scanf("%lld",&p1);
        if(p1<=m)
        {	
        	p[j]=p1;
        	j++;
		}
		for(i=0;i<n;i++)
        scanf("%lld",&v[i]);
    }
       
}