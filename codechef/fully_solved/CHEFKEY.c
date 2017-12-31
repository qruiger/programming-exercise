#include<stdio.h>
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
     	LL j,m,n,c,count=0,i;
     	scanf("%lld %lld %lld",&n,&m,&c);
     	if(m*n < c)
     	{
     		printf("0\n");
     		continue;
     	}	
     	for(i=1;i<=n;i++)
     	{
     		for(j=1;j<=m;j++)
     		{
     			if(i*j > c)
     				break;
     			if(i*j == c)
     				count++;
     		}
     	}
     	printf("%lld\n",count); 
    }
   return 0; 
}