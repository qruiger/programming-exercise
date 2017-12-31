#include<stdio.h>
int main()
{
	long int T;
	scanf("%ld",&T);
	while(T--)
	{
		int i,m,x,y,j,l,f,t,v;
		scanf("%d %d %d",&m,&x,&y);
		j=x*y;
		int a[101]={0};
		l=100;
		for(i=0;i<m;i++)
		{
			scanf("%d",&f);
			if((f-j)<=0)
				t=1;
			else
				t=f-j;
			if((f+j)>100)
				v=100;
			else
				v=f+j;
			while(t<=v && l>=0) 
			{
				if(a[t]==0) //enters if the array is not filled by any element
				{
					a[t]=1; //fills it with certain value, to prevent filling next time
					l--;    //100-l,basically 100-occupied which gives unoccupied
				}
				t++;
			}
		}
		printf("%d\n",l);
	}
	return 0;
} 
