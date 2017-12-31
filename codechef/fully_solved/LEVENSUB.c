#include<stdio.h>
#include<math.h>
#define LL int long long
LL max(LL a,LL b)
{
    LL m=a>b?a:b;
    return m;
} 
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        LL n,i,c=0,fo,lo;
        scanf("%lld",&n);
        LL a[n];
        for(i=1;i<=n;i++)
        { 	
            scanf("%lld",&a[i]);
            if(a[i]%2!=0)
            {
                c++;lo=i;//position of last odd
                if(c==1)
                    fo=i;//position of first odd
            }	
        }
        if(c%2==0)
        {
         printf("%lld\n",n);
        }
        else
            printf("%lld\n",max(n-fo,lo-1));//max of position of first and last odd
    }
   return 0;
} 
