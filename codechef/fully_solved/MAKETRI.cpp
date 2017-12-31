#include <bits/stdc++.h>
using namespace std;
#define LL int long long
LL a[1000005],ans=0,L,R;
struct Interval
{
   LL s,e;
};
bool comp(Interval a, Interval b)
{   
	return a.s>b.s; 
} 
void merge(Interval a[], LL n)
{
    sort(a,a+n,comp);
    LL ind=0,i; 
    for(i=0;i<n;i++)
    {
        if(ind!=0&&a[ind-1].s<=a[i].e)
        {
            while(ind!=0&&a[ind-1].s<=a[i].e)
            {
                a[ind-1].e=max(a[ind-1].e,a[i].e);
                a[ind-1].s=min(a[ind-1].s,a[i].s);
                ind--;
            }
        }
        else
            a[ind]=a[i];
 		ind++;
    }
    /*cout<<"\nThe Merged Intervals are: ";
    for (LL i=0;i<ind;i++)
        cout << "[" << a[i].s << ", " << a[i].e << "] ";
    printf("\n");*/
    for(i=0;i<ind;i++)
    {
    	if(a[i].s>=L && a[i].e<=R)
    	{
    		ans+=(a[i].e-a[i].s)+1;
    	}
    }
    printf("%lld\n",ans);
}
int main()
{
	LL i,n,maxval,minval,ans=0,k=0;
	Interval b[1000005];
	scanf("%lld %lld %lld",&n,&L,&R);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	for(i=n-1;i>0;i--)
	{
		maxval=(a[i]+a[i-1])-1;
		minval=abs(a[i]-a[i-1])+1;
		//printf("minval=%lld maxval=%lld\n",minval,maxval);
		if((minval<L && maxval<L) || (minval>R && maxval>R))
		{
			continue;
		}
		if(minval<L)
			minval=L;
		if(maxval>R)
			maxval=R;
		b[k].s=minval;
		b[k].e=maxval;
		k++;
	}
	merge(b,k);
	return 0; 
} 