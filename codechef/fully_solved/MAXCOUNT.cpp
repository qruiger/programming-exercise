#include<cstdio>
#include<climits>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
 		LL n,i;
 		scanf("%lld",&n);
 		LL m=0,a[n],b[10005]={0},max=0,val;
 		for(i=0;i<n;i++)
 		{	
 			scanf("%lld",&a[i]);
 			max=max<a[i]?a[i]:max;
 			b[a[i]]++;
 		}
 		for(i=0;i<=max;i++)
 		{
 			if(b[i]!=0)
 			{
 				if(m<b[i])
 				{
 					m=b[i];
 					val=i;
 				}	
 			}
 		}
 		printf("%lld %lld\n",val,m);
    }
 	return 0; 
}