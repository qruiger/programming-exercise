#include<stdio.h>
#include<string.h>
#define LL long long int
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,flag=0,i,t=0,f,j,c=0;
		scanf("%d %d",&n,&m);
		char a[n][m];
		for(i=0;i<n;i++)
		scanf("%s",a[i]);
		for(j=0;j<m;j++)
        	{
        		c=0;
        		for(i=0;i<n;i++)
        		{
        			if(a[i][j]!='0')
        				c++;
        		}
        		if(c>=2)
        		{
            	 		flag++;
             			for(f=c-1;f>=1;f--)
             				t+=f;
            		}
        	}
		if(flag>0)
			printf("%d\n",t);
		if(flag==0)
			printf("0\n");
	}
    	return 0;
}
