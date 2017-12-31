#include<stdio.h>
int main()
{
	int T,i,y,o,n,N,c;
	char a[1001];
	scanf("%d",&T);
	while(T--)
	{
		n=0;i=0;y=0;
		scanf("%d",&N);
		scanf("%s",a);
		for(c=0;c<N;c++)
		{
			if(a[c]=='N')
				n++;
			if(a[c]=='Y')
				y++;
			if(a[c]=='I')
				i++;
		}
		if(i>0)
			printf("INDIAN\n");
		if(y>0)
			printf("NOT INDIAN\n");
            	if(y==0 && i==0)
            		printf("NOT SURE\n");

		
	}
	return 0;
}
