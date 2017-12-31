#include<stdio.h>
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        LL n,m;
        scanf("%lld %lld",&n,&m);
        if(n%2!=0 && m%2!=0)
            printf("No\n");
        else
            printf("Yes\n");	
    }
    return 0; 
}
