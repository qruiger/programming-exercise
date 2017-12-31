#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
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
 		 LL n;
 		 scanf("%lld",&n);   	
 		 LL a[n],count=0,i;
 		 for(i=0;i<n;i++)
 		 	scanf("%lld",&a[i]);
 		 sort(a,a+n);
 		 for(i=0;i<n-1;i++)
 		 {
 		 	if(a[i]!=a[i+1])
 		 		count++;
 		 }
 		 printf("%lld\n",count+1);
    }
   return 0; 
}