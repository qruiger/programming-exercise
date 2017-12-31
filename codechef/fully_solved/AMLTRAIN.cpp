#include <cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,temp;
		scanf("%d",&n);
		temp=n;
		if(temp>8)
		temp%=8;
		if(temp == 3)
			printf("%dUB\n",n+3);
		if(temp == 6)
			printf("%dUB\n",n-3);
		if(temp == 2)
			printf("%dMB\n",n+3);
		if(temp == 5)
			printf("%dMB\n",n-3);
		if(temp == 1)
			printf("%dLB\n",n+3);
		if(temp == 4)
			printf("%dLB\n",n-3);
		if(temp == 7)
			printf("%dSU\n",n+1);
		if(temp == 8 || temp == 0)
			printf("%dSL\n",n-1);				  
	}
	return 0; 
}
