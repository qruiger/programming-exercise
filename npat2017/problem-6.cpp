//Additive sequence of an array
#include <bits/stdc++.h>
using namespace std;
int checkAddSeq(int *x, int *y, int n) 
{
  	for(int i = 0; i < n; i++) 
  	{
  		int sum=0,j=0;
  		while(j<=i)
  		{
  			sum+=x[j];
  			j++;
  		}
		if(sum!=y[i])
			return 0;
  	}
  	return 1;
}
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int x[n+5],y[n+5];
		for(int i=0;i<n;i++)
			scanf("%d",&x[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&y[i]);
		printf("%d\n",checkAddSeq(x,y,n));		
	}
	return 0; 
}