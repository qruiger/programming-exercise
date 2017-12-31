#include <stdio.h>
#include <math.h>
#define LL int long long 
int main()
{
  int t,flag;
  scanf("%d",&t);
  while(t--)
  {
    LL m,n,k,i,temp;
    scanf("%lld %lld",&m,&n);
    for(i=m;i<=n;i++)
    {
      if(i==2)
        printf("%lld\n",i);
      if(i!=1 && i%2!=0) //i is odd and !1
      {
        temp=i;
        flag=0;
        for(k=2;k<=sqrt(temp);k++)
        {
          if(temp%k==0)
          {
            flag=1;
            break;
          }
        }
        if(flag==0)
          printf("%lld\n",i);
      }
    }
    printf("\n");
  }
  return 0; 
} 
