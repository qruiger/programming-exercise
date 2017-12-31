#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define LL int long long
#define lim 1000005
LL gcd(LL a, LL b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL g,n,m,lcm;
		scanf("%lld %lld",&n,&m);
		g=gcd(n,m);
		lcm=(n*m)/g;
		printf("%lld %lld\n",(lcm/n)-1,(lcm/m)-1);
	}
	return 0; 
} 