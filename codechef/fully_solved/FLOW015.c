#include<stdio.h>
int main()
{
	int T,y,c,i,j;
	scanf("%d",&T);
	while(T--)
	{
		c=0;
		scanf("%d",&y);
		if(y==2001)
			c=0;
		if(y>2001)
		{	
			for(i=2001;i<y;i++)
			{	
				if( (i%400==0) || (i%100!=0 && i%4==0))
					c+=366;
			 	else
					c+=365;
			}
		}
		if(y<2001)
		{
			for(i=1900;i<y;i++)
			{	
		 		if( (i%400==0) || (i%100!=0 && i%4==0))
					c+=366;
		 		else
					c+=365;
			}
		} 
		printf("%d\n",c);
		switch(c%7)
		{
			case 0:printf("monday\n");
				 break;
			case 1:printf("tuesday\n");
				 break;
			case 2:printf("wednesday\n");
				 break;
			case 3:printf("thursday\n");
				 break;
			case 4:printf("friday\n");
				 break;
			case 5:printf("saturday\n");
				 break;
			case 6:printf("sunday\n");
				 break;
		}

	}
	return 0;
}
