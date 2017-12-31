#include <cstdio>
#include <cmath>
using namespace std;
#define LL int long long
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL cats,dogs,legs,nc,nd,min=0;
		scanf("%lld %lld %lld",&cats,&dogs,&legs);
		nc=cats*4;nd=dogs*4;
		if(nc+nd==legs)
		{
			printf("yes\n");
			continue;
		}
		else if(legs<4 || legs%4!=0 || legs>(nc+nd))
		{	
			printf("no\n");
			continue;		
		}
		else if(cats<=dogs)
		{	
			if(legs>=nd)
			{
				printf("yes\n");
				continue;
			}
			else
			{
				printf("no\n");
				continue;
			}		
		}
		else if(cats>dogs)
		{
			min+=nd;	
			if((dogs*2)<cats)
			{
				min+=(cats-(dogs*2))*4;
			}
			//printf("%lld\n",min);
			if(legs>=min)
			{	
				printf("yes\n");
				continue;
			}
			else
			{	
				printf("no\n");
				continue;
			}
		}
	}
	return 0; 
} 