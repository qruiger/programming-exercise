/*input
4
10
1 1 1 1 1 1 1 1 1 1
19
1 2 3 4 4 5 6 6 6 7 6 6 6 5 4 4 3 2 1
14
1 2 3 4 5 6 7 6 5 4 3 2 1 1
13
1 2 3 4 5 6 8 6 5 4 3 2 1
*/
#include <bits/stdc++.h>
using namespace std;
int a[110],b[110],c[110],d[110];
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n,max_val=0,max_index,c0,c1,c2,c3,c4,c5,count=0,occ=0;
		c0=c1=c2=c3=c4=c5=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{	
			scanf("%d",&a[i]);
			if(a[i]>=max_val)
			{
				max_val=a[i];
				max_index=i;
			}
		}
		if(max_val<7)
		{
			printf("no\n");
			continue;
		}
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1])
			{
				count++;
			}
		}
		if(count==n-1)
		{c0=1;}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==max_val)
			{
				occ++;
			}
		}
		int checka[max_val+5];
		for(int i=1;i<=max_val;i++){checka[i]=0;}
		for(int i=1;i<=max_index-occ;i++)
		{
			checka[a[i]]++;
			b[i]=a[i];
		}
		for(int i=1;i<max_val;i++)
		{
			if(checka[i]==0)
			{
				c1=1;
				break;
			}
		}
		int checkb[max_val+5];
		for(int i=1;i<=max_val;i++){checkb[i]=0;}
		int k=1;
		for(int i=max_index+1;i<=n;i++)
		{
			checkb[a[i]]++;
			c[(i-(max_index+1))+1]=a[i];
			k++;
		}
		k--;
		for(int i=1;i<max_val;i++)
		{
			if(checkb[i]==0)
			{
				c2=1;
				break;
			}
		}
		if(k!=max_index-occ)
		{
			printf("no\n");
			continue;
		}
		sort(b+1,b+(max_index-occ)+1);
		for(int i=1;i<=k;i++){d[i]=c[i];}
		sort(c+1,c+k+1,greater<int>());
		for(int i=1; i<=max_index-occ; i++)
		{
			if(a[i]!=b[i])
			{
				c3=1;
				break;
			}
		}
		for(int j=max_index+1,z=1; j<=n && z<=k; j++,z++)
		{
			if(a[j]!=c[z])
			{
				c4=1;
				break;
			}
		}
		sort(d+1,d+k+1);
		for(int i=1;i<=k;i++)
		{
			if(b[i]!=d[i])
			{
				c5=1;
				break;
			}
		}
		if(c0==1||c1==1||c2==1||c3==1||c4==1||c5==1)
		{
			printf("no\n");
			continue;
		}
		printf("yes\n");
	}
	return 0; 
}