#include <bits/stdc++.h>
using namespace std;
#define LL unsigned int long long
LL digitalRoot(LL val) 
{
  return val%9==0?9:val%9;
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL A,n,val,sum,ans;
		scanf("%llu %llu",&A,&n);
		val=digitalRoot(A);
		int two[]={1,2,4,8,7,5};
		int four[]={1,4,7};
		int five[]={1,5,7,8,4,2};	
		int seven[]={1,7,4};
		int eight[]={1,8};
		switch(val)
		{
			case 1: printf("1\n");
					break;
			case 2:	printf("%d\n",two[n%6]);
					break;
			case 4: printf("%d\n",four[n%3]);
					break;
			case 5:	printf("%d\n",five[n%6]);
					break;
			case 7:	printf("%d\n",seven[n%3]);
					break;
			case 8:	printf("%d\n",eight[n%2]);
					break;
			case 3:	if(n>1) printf("9\n");
					else	printf("3\n");
					break;	
			case 6:	if(n>1) printf("9\n");
					else	printf("6\n");
					break;	
			case 9:	printf("9\n");
					break;		
		}
	}
	return 0; 
}