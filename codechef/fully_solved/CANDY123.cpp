#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL L,B,even=0,odd=0,i;
		scanf("%lld %lld",&L,&B);
		for(i=1;;i++)
		{
			if(i%2!=0)
				odd+=i;
			if(i%2==0)
				even+=i;
			if(odd>L)
			{
				printf("Bob\n");
				break;
			}
			if(even>B)
			{
				printf("Limak\n");
				break;
			}

		}
	}
	return 0; 
}