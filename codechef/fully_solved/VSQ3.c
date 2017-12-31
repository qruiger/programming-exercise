#include<stdio.h>
#include<limits.h>
long long int smax(long long int[], long long int ,long long int[] );
int main()
{
    long long int T,i,k,j,n,t,f,c,a[100000],q[4],flag,max;
    scanf("%lld",&T);
    while(T--)
    {
        flag=0;
        max=INT_MIN;
        c=0,j=0;   
        scanf("%lld",&n);
        for(i=0;i<4;i++)
            scanf(" %lld",&q[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            if (a[i]>=0 && (a[i]!=q[0] && a[i]!=q[1] && a[i]!=q[2] && a[i]!=q[3]))
                flag=1;
            if(a[i]!=q[0] && a[i]!=q[1] && a[i]!=q[2] && a[i]!=q[3])
            {  
                if(max<=a[i])
                    max=a[i];
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==q[0] || a[i]==q[1] || a[i]==q[2] || a[i]==q[3])
                c++;
        }
        if(c==n)
        {
            printf("0\n");
            continue;
        }
        if(flag==0)
        {
            printf("%lld\n",max);
            continue;
        }
        if(flag==1)
        {
            printf("%lld\n",smax(a,n,q));
            continue;
        }
    }
    return 0;
}
long long int smax(long long int a[],long long int n,long long int q[])
{
    long long int mf=0,cm=0,i;
    for (i=0;i<n;i++)
    {
        cm+=a[i];
        if(cm<0 || a[i]==q[0] || a[i]==q[1] || a[i]==q[2] || a[i]==q[3])
            cm=0;
        if(mf<cm)
            mf=cm;
    }
    return mf;
}
