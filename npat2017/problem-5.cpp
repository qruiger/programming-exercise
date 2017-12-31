//Largest sum of m consecutive elements
#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
int a[lim];
int maxConsecutive(int *a, int n, int m) 
{
  	int sum = 0;
  	for(int i = 0; i < m; i++) 
  	{
    	sum += a[i];
  	}
  	int max = sum;
  	for(int i = m; i < n; i++) 
  	{
  		int k,sum=0,bahar=1;
		if(i==m)
		{
			k=i-1;
		}
		else
		{	
			k=i;
		}
	    while(bahar<=m && k<n)
	    {
	      sum+=a[k];
	      bahar++;
	      k++;
	    }
	    if(sum>max)
	    	max=sum;
	    if(i==n-1 && m==1)
	    {
	    	sum=0;
	    	sum+=a[n-1];
		    if(sum>max)
	    		max=sum;
	    }
	    if(sum>max)
	    	max=sum;
   	}
    return max;
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",maxConsecutive(a,n,m));
	}
	return 0; 
}
