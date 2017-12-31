#include<cstdio>
using namespace std;
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
 		LL i,n,p,count=0;
 		scanf("%lld %lld",&n,&p);
 		LL a[n];
 		for(i=0;i<n;i++)
 		{
 			scanf("%lld",&a[i]);
 			if(a[i]>=p)
 				count++;
 		}
 		printf("%lld\n",count);
    }
 	return 0; 
}