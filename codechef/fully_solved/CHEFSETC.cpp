#include <cstdio>
using namespace std;
#define LL unsigned int long long
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL a,b,c,d;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if(a==0 || b==0 || c==0 || d==0 || a+b==0 || a+c==0 || a+d==0 || b+c==0 || b+d==0 || c+d==0 || a+b+c==0 || a+b+d==0 || a+c+d==0 || b+c+d==0 || a+b+c+d==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0; 
} 