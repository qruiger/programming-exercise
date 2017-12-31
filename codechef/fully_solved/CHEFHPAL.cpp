#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL n,x,A,k;
void generic()
{
	n-=2;
	LL p;
	printf("4 ");
	printf("bb");
	for(LL i=1;i<=n/6;i++)
	{
		printf("bbabaa");
	}
	p=n%6;
	switch(p)
	{
		case 1: printf("b");
				break;	
		case 2: printf("bb");
				break;	
		case 3: printf("bbb");
				break;	
		case 4: printf("bbbb");
				break;	
		case 5: printf("bbaba");
				break;	
	}
	printf("\n");	
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&A);
		if(A==1)
		{
			printf("%lld ",n);
			for(LL i=1;i<=n;i++)
				printf("a");
			printf("\n");
			continue;
		}
		if(A==2)
		{
			if(n==1)
			{
				printf("1 b\n");
			}
			if(n==2)
			{
				printf("1 ba\n");
			}
			if(n==3)
			{
				printf("2 bba\n");
			}
			if(n==4)
			{
				printf("2 bbaa\n");
			}
			if(n==5)
			{
				printf("3 bbbab\n");
			}
			if(n==6)
			{
				printf("3 bbabaa\n");
			}
			if(n==7)
			{
				printf("3 bbbabaa\n");
			}
			if(n==8)
			{
				printf("3 bbbabaaa\n");
			}
			if(n>8)
			{
				//generic();
				printf("4 ");
				char s[]="bbabaa";
				k=0;
				for(int i=1;i<=n;i++)
				{
					if(k==6)
						k=0;
					printf("%c",s[k++]);
				}
				printf("\n");
			}
		}
		if(A>=3)
		{
			printf("1 ");
			int k=97;
			for(int i=1;i<=n;i++)
			{	
				k=k==100?97:k;
					printf("%c",k++);
			}
			printf("\n");		
		}
	}
	return 0; 
}