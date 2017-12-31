#include<stdio.h>
int main()
{
	int T,i,f,c,n,r;
	scanf("%d",&T);
	while(T--)
	{
		f=0;
		scanf("%d",&n);
		while(n>0)
		{
			r=n%10;
			if(r==4)
				f++;
			n/=10;
		}
		printf("%d\n",f);
	}
	return 0;
}
