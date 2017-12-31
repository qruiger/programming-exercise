#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define LL int long long
int main()
{
	LL t,i; 
	scanf("%lld",&t);
	while(t--)
	{
		double n,amount,sum=0;
		scanf("%lf %lf",&n,&amount);
		double exp[100005];
		for(i=0;i<n;i++)
		{	
			scanf("%lf",&exp[i]);
			sum+=exp[i];
		}
		if(sum<=amount && (amount-sum)>=(amount/2))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0; 
} 