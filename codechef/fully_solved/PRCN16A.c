#include<stdio.h>
#include<math.h>
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
      LL n,sum=1,sum1=1,sum2=1,o=0,e=0,i,osum=1,f=0,j,flag;
      scanf("%lld",&n);
      LL a[n];
      if(n==1)
      {
      	printf("1\n");
      	continue;
      }	
      while(n%2==0)
      {
      	e+=1;
        n=n/2;
      }
      for(i=1;pow(2,i)<=pow(2,e);i++)
      sum+=pow(2,i);	
      for(i=3;i<=sqrt(n);i+=2)
      {
      	flag=0,o=0;
        while(n%i==0)
        {
            flag=1;
        	  o+=1;
            n=n/i;
        }
        if(flag==1)
        {
            sum1=1;	
            for(j=1;pow(i,j)<=pow(i,o);j++)
            sum1+=pow(i,j);
            a[f]=sum1;
            f++;
        }	
      }
      if(n>2)
      sum2+=n;
      for(i=0;i<f;i++)
      osum*=a[i];
      printf("%lld\n",osum*sum2*sum);
    }
   return 0;
} 
