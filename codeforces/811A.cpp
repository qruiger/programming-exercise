#include <bits/stdc++.h>
using namespace std;
#define LL int long long
int main()
{
	LL a,b;
	scanf("%lld %lld",&a,&b);
	LL even=2;
	LL odd=1;
	LL it=1;
	//printf("a=%lld b=%lld\n",a,b);
	while(1)
	{
		if(it%2!=0)
		{
			a-=odd;
			odd+=2;
		}
		if(it%2==0)
		{
			b-=even;
			even+=2;
		}
		//printf("a=%lld b=%lld\n",a,b);
		if(a<0)
		{
			printf("Vladik\n");
			break;
		}
		if(b<0)
		{
			printf("Valera\n");
			break;
		}
		it++;
	}
	return 0; 
} 
