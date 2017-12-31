#include<stdio.h>
#include<climits>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long int p,m=INT_MAX,i,c=0,diff;
		scanf("%ld",&p);
		int a[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
		for(i=11;i>=0;i--)
		{
			diff=p-a[i];
			if(diff<m && diff>=0)
			{
				m=diff;
				c++;
				p=m;
				if(p>=2048)
					i=12;
			}
		}
		printf("%ld\n",c);
	}
	return 0;
}
