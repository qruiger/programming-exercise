#include<stdio.h>
int main()
{
	int T;
	char s;
	scanf("%d",&T);
	while(T--)
	{
		scanf(" %c",&s); //space before %c so that enter pressed after inputting T goes there
		if(s<97)
			s+=32;
		switch(s)
		{
			case 'b':printf("BattleShip\n");
				 break;
			case 'c':printf("Cruiser\n");
				 break;
			case 'd':printf("Destroyer\n");
				 break;
			case 'f':printf("Frigate\n");
				 break;
		}  
	}
	return 0;
}
