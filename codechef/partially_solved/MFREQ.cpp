#include <bits/stdc++.h>
using namespace std;
#define LL int long long
LL a[100005],n,m,k,L,R,i;
void search()
{
	LL count=0,flag=0,val;
	for(i=L;i<R;i++)
	{
		if(a[i]==a[i+1])
		{	
			count++;
			val=a[i];
		}
		if(count>=k-1)
		{
			flag=1;
			printf("%lld\n",val);
			break;
		}
		else if(a[i]!=a[i+1])
		{
			count=0;
		}
	}
	if(flag==0)
		printf("-1\n");
}
int main()
{	
	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	while(m--)
	{
		scanf("%lld %lld %lld",&L,&R,&k);
		L--,R--;
		if(L==R && k==1)
		{
		    printf("%lld\n",a[L]);
		    continue;
		}
		search();
	}
	return 0; 
}   