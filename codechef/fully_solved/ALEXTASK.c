#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define LL int long long
LL gcd(LL a, LL b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
} 
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
     	LL n,lcm,i,j,g,min=1000000000000000001;
        scanf("%lld",&n);
        LL a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        int flag=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                g=gcd(a[i],a[j]);            
                lcm=(a[i]*a[j])/(g);
                min=min>lcm?lcm:min;
            }  
        }
        printf("%lld\n",min);
    }
   return 0; 
}