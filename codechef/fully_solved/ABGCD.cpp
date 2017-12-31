#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000005
LL a[lim],f[lim],n,phi[lim];
void computeTotient(LL n)
{
    for (LL i=1; i<=n; i++)
        phi[i] = i; 
    for (LL p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;
            for (LL i = 2*p; i<=n; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
}
LL findmax(LL L, LL R)
{
	LL val=-1,i;
	for(i=L;i<=R;i++)
	{
		val=max(val,f[i]);
	}
	return val;
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL q,i,L,R,qtype,largest=-1,k;
		scanf("%lld %lld",&n,&q);
		for(i=0;i<n;i++)
		{	
			scanf("%lld",&a[i]);
			largest=max(largest,a[i]);
		}
		computeTotient(largest);
		for(k=0;k<n;k++)
			f[k]=phi[a[k]];
		while(q--)
		{
			scanf("%lld %lld %lld",&qtype,&L,&R);
			if(qtype==1)
			{
				a[L-1]=R;
				if(R<=largest)
				{	
					f[L-1]=phi[a[L-1]];
				}
				else
				{					
					computeTotient(a[L-1]);
					f[L-1]=phi[a[L-1]];
				}
			}	
			else
			{	
				L--,R--;
				printf("%lld ",findmax(L,R));
			}
		}
		printf("\n");
	}
	return 0; 
} 
