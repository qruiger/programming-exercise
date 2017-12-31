/*reference taken from 
http://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/*/
#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 500005
LL a[lim],b[lim],op[lim];
char s[lim];
void binToCount(LL k,LL n)
{
	LL ans=0,count_here=0,z=0;
	for(LL i=0;i<k;i++)
		ans+=a[i];
	count_here=ans;
	b[z++]=count_here;
	for(LL i=k;i<n;i++)
	{
		count_here+=a[i]-a[i-k];
		b[z++]=count_here;
		ans=max(ans,count_here);
	}
}
void slidingWindow(LL *a,LL n,LL k)
{
    deque<LL>Qi(k);
    LL i,z=0;
    for (i=0;i<k;i++)
    {
        while((!Qi.empty()) && a[i]>=a[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    while(i<n)
    {
        op[z++]=a[Qi.front()];
        while((!Qi.empty())&&Qi.front()<=i-k)
            Qi.pop_front(); 
        while ((!Qi.empty()) && a[i]>=a[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
        i++;
    }
    op[z]=a[Qi.front()];
}
int main()
{
	LL N,one=0,n,k,p,j,i;
	scanf("%lld %lld %lld",&n,&k,&p);
	if(k>n)
		k=n;
	LL z=0;
	LL k1=(n-k)+1;
	N=n+(k-1);
	for(LL i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]==1)
        	one++;
    }
    LL blim=n+((n-k)+1);
    for(LL i=n;i<N;i++)
		a[i]=a[z++];
	binToCount(k,N);
	z=0;
	for(LL i=n;i<blim;i++)
		b[i]=b[z++];
	slidingWindow(b,blim,k1);
    for(i=1,j=n-1;i<j;i++,j--)
    	swap(op[i],op[j]);
 
	/*cout<<"a"<<endl;
	for(LL i=0;i<N;i++)
        printf("%lld ",a[i]);
    printf("\n");
	cout<<"b"<<endl;
	for(LL i=0;i<blim;i++)
        printf("%lld ",b[i]);
    printf("\n");
    cout<<"op"<<endl;
    for(i=0;i<n;i++)
    	printf("%lld ",op[i]);
    printf("\n");*/
 
    scanf("%s",s);
    z=0;
    for(LL i=0;i<p;i++)
	{
		if(s[i]=='?')
		{
			if(k==n)
			{
				printf("%lld\n",one);
				continue;
			}
			if(z>=n)
				printf("%lld\n",op[z%n]);
			if(z<n)
				printf("%lld\n",op[z]);
		}
		if(s[i]=='!')
			z++;
	}
	return 0; 
}    