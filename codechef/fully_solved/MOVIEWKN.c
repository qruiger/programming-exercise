#include<stdio.h>
int main()
{
	int T,n,m1,m2,y,i;
	int L[100],R[100],b[100];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&L[i]);
        	for(i=0;i<n;i++)
			scanf("%d",&R[i]);
		for(i=0;i<n;i++)
			b[i]=L[i]*R[i];
		m1=b[0];
		y=0;
		m2=R[0];
		for(i=1;i<n;i++)
		{
			if(m1<b[i])
			{
				y=i;
				m1=b[i];
				m2=R[i];
			}
			if(m1==b[i])
			{
				if(m2<R[i])
				{
					m1=b[i];
					m2=R[i];
					y=i;
				}
			}
		}
		printf("%d\n",y+1);
	}
        return 0;
}
