#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define LL unsigned int long long
LL max(LL a,LL b)
{
  LL m=a>b?a:b;
  return m;
} 
int main()
{
    LL n,m,i,sum=0,answer=0,left=0, right=0;
    scanf("%lld %lld",&n,&m);
    LL a[n];
    for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    while(left<=n-1)
    {
        while(right <= n-1 && sum + a[right] <= m)
        {
            sum+=a[right];
            right++;
        }
        answer = max(sum,answer);
        sum -= a[left];
        left++;
    }
    printf("%lld\n",answer);    
    return 0; 
}
