#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int x,y,x1,y1,x2,y2;	
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	scanf("%d %d",&x,&y);
	if(abs(y2-y1)%y==0 && abs(x2-x1)%x==0 && ((x2-x1)/x-(y2-y1)/y)%2==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0; 
} 
