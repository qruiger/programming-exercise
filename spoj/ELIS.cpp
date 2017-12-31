#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define vv 1000001
#define LL int long long
LL s[vv],a[vv],n;
LL binarysearch(LL low, LL high, LL item)
{
    LL mid;
    if(item<=s[low])
        return low;
    mid=(low+high)/2;
    if(s[mid]==item)
        return mid;
    else if(s[mid]<item)
    {
        if(item<=s[mid+1] && mid+1<=high)
            return mid+1;
        else
            return binarysearch(mid+1,high,item);
    }
    else
    {
        if(item>s[mid-1] && mid-1>=low)
            return mid;
        else
            return binarysearch(low,mid-1,item);
    }
}
LL LIS()
{
    LL i,k=0,pos,len=0;
    for(i=0;i<n;i++)
        s[i]=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>s[k-1])
        {	
            s[k++]=a[i];
        }
        else
        {
            pos=binarysearch(0,k-1,a[i]);
            s[pos]=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(s[i]!=0)
        {	
            len++;
        }
    }
    return len;
}	
int main()
{
    LL i;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    printf("%lld\n",LIS());		
    return 0; 
} 
