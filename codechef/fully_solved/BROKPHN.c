#include<stdio.h>
int main()
{
    int n,t,i,x;
    scanf("%d",&t);
    while(t--)
    {
        x=0;
        scanf("%d",&n);
        long long int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        if(a[0]!=a[1])
            x++;
        if(a[n-1]!=a[n-2])
            x++;
        for(i=1;i<n-1;i++)
        {
            if((a[i]!=a[i+1])||(a[i]!=a[i-1]))
                x++;
        }
        printf("%d\n",x);
    }
    return 0;
}
 
