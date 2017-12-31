#include<cstdio>
#include<cmath>
using namespace std;
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
 		LL n;
 		scanf("%lld",&n);
 		if(n%2==0)
 			printf("ALICE\n");
 		else
 			printf("BOB\n");   		  
    }
 	return 0; 
}