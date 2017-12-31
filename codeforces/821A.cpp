#include <bits/stdc++.h>
using namespace std;
#define LL int long long
LL a[55][55],b[1005],c[1005],k,n;
bool findPair(LL i,LL j)
{
	LL left=1,right=k;
	LL sum=a[i][j];
	while(left<right && left<=((n-1)*2)/2 && right>=((n-1)*2)/2)
	{
		if(b[left]+b[right]>sum)
			right--;
		else if(b[left]+b[right]<sum)
			left++;
		else
			return true;
	}
	return false;
}
void makeLinearArray(LL i, LL j)
{
	k=1;LL z=1;
	for(LL row=1;row<=n;row++)
	{
		if(row!=i)	
			b[k++]=a[row][j];
	}
	k--;
	sort(b+1,b+k+1);
	for(LL col=1;col<=n;col++)
	{
		if(col!=j)
			c[z++]=a[i][col];
	}
	z--;
	sort(c+1,c+z+1);
	k++;
	for(LL p=1;p<=z;p++)
	{
		b[k++]=c[p];
	}
	k--;
}
int main()
{	
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++)
	{
		for(LL j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	int flag=0;
	for(LL i=1;i<=n;i++)
	{
		for(LL j=1;j<=n;j++)
		{
			if(a[i][j]!=1)
			{
				makeLinearArray(i,j);
				if(findPair(i,j)==false)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)
			break;
	}
	if(flag)
		printf("No\n");
	else
		printf("Yes\n");
	return 0; 
}
