#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,k,dif,n1,m1;
		scanf("%d %d %d",&n,&m,&k);
		dif=n>m?n-m:m-n;
		if(dif<=k)
			printf("0\n");
		if(dif>k)
			printf("%d\n",dif-k);
	}
	return 0;
} 
