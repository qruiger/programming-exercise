#include<stdio.h>
#include<string.h>
int main()
{
	int T,a,r,bfc,ot,l,i;
	char o[7]={"INDIAN"};
	char cw[12]={"CONTEST_WON"};
	char tc[16]={"TOP_CONTRIBUTOR"};
	char bf[10]={"BUG_FOUND"};
	char ch[15]={"CONTEST_HOSTED"};
	scanf("%d",&T);
	char o1[20];
	char b[20];     
	while(T--)
	{
		ot=0;
		l=0;
		scanf("%d",&a);
		scanf("%s",o1);
		if(strcmp(o,o1)==0)
			ot=1;
		for(i=1;i<=a;i++)      
		{ 
			scanf("%s",b);
			if(strcmp(cw,b)==0)
			{     
				scanf("%d",&r);
				l+=300;
				if(r<=20)
				{ 
					l+=(20-r);
				}
			}
			if(strcmp(tc,b)==0)
				l+=300;
			if(strcmp(bf,b)==0)
			{    
				scanf("%d",&bfc);
				l+=bfc; 
			}
			if(strcmp(ch,b)==0)
				l+=50;
		} 
		if(ot==1)
			printf("%d\n",l/200);
		else
			printf("%d\n",l/400);
	}
	return 0;
}
