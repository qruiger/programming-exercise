#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
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
    	LL L,O,i,j,ans=0,sum;
     	scanf("%lld %lld",&L,&O);
     	/*for(i=1;i<=L;i++)
     	{
     		for(j=i+1;j<=L;j++)
     		{
     			sum=i+j;
     			if(sum%O==0)
     			{
     				// /printf("i=%lld j=%lld\n",i,j);	
     				ans++;
     			}
     		}
     	}*/
     	printf("%lld\n",L);
    }
   return 0; 
}