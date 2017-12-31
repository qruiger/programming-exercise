#include <cstdio>
#include <algorithm>
using namespace std;
#define LL int long long
int main()
{
  LL t;
  scanf("%lld",&t);
  while(t--)
  {
    LL m,count=0,n,p,q,i;
    scanf("%lld %lld %lld",&n,&p,&q);
    LL a[n];
    for(i=0;i<n;i++)
      scanf("%lld",&a[i]);
    sort(a,a+n);
    m=p==0?q:p;
    for(i=0;i<n;i++)
    {
      if(p==0)
      {  
        if((a[i]%2==0) && (a[i]<=(m*2)))
        {  
          if((m-(a[i]/2))>=0)
          {
            count++;
            m-=(a[i]/2);
          }
          else
            break;
        }
      }
      if(q==0)
      {
        if(m-a[i]>=0)
        {
          count++;
          m-=a[i];
        }
        else
          break;
      }
    }
    printf("%lld\n",count);
  }  
  return 0; 
} 