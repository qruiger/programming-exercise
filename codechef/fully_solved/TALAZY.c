#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
    	LL n,m,t1=0,b,p;
      	scanf("%lld %lld %lld",&n,&b,&m);
      	while(1)
      	{
      		if(n==1)
      		{
      			t1+=m;
      			break;
      		}	
      		if(n%2!=0)
      		{
      			p = (n+1)/2 ;	
      			t1+= (p*m)+b;
      			n -= (n+1)/2;
      		}	
      		else
      		{
      			p = n/2;
      			t1+=(p*m)+b;
      			n -= n/2;
      		}
      		m*=2;	
      	}
      	printf("%lld\n",t1);
    }
   return 0; 
}
