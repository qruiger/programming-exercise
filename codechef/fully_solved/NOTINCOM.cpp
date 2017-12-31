#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL int long long
LL bsearch(LL *ss,LL left,LL  right,LL element)
{
   if(right>=left)
   {
        LL mid=left+(right-left)/2;
        if(ss[mid]>element) 
            return bsearch(ss,left,mid-1,element);
        if(ss[mid]==element)  
            return mid;
        return bsearch(ss,mid+1,right,element);
   }
   return -1;
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,m,a[100005],b[100005],count=0,i,j,ind;
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(j=0;j<m;j++)
			scanf("%lld",&b[j]);
		sort(a,a+n);
		sort(b,b+m);
		for(i=0;i<n;i++)
		{
			ind=bsearch(b,0,m-1,a[i]);
			if(ind==-1)
				continue;
			count++;	
		}
		printf("%lld\n",count);
	}
	return 0; 
} 