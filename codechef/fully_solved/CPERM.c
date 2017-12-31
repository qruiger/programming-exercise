#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#define LL unsigned long long int
LL power(LL a,LL b,LL p)
{
    LL ans=1;
    a=a%p; 
    while(b>0)
    {
        if (b&1)
            ans=(ans*a)%p;
        b=b>>1;
        a=(a*a)%p;  
    }
    return ans;
} 
int main()
{
    LL t;
    scanf("%llu",&t);
    while(t--)
    {
     	LL N,a,i;
     	scanf("%llu",&N);
     	if(N==1)
     	{
     		printf("0\n");
     		continue;
     	}
        a=power(2,N-1,1000000007);
        printf("%llu\n",a-2);
    }
   return 0; 
}