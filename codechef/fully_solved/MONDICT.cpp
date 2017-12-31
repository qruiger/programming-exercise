#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 1000005
LL a[lim];
int main()
{
	string str;
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i,count=0;
		cin>>str;
		bool val;
		while(1)
		{
			val=next_permutation(str.begin(),str.end());
			if(val==true)
				count++;
			else
				break;
		}
		printf("%lld\n",count);
	}
	return 0; 
} 