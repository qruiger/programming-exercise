#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
     	 LL s,v;
     	 scanf("%lld %lld",&s,&v);
     	 long double t;
     	 t = (long double)(2*s)/(3*v);
     	 printf("%.7Lf\n",t);
    }
   return 0; 
}