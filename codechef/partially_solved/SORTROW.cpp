#include <bits/stdc++.h>
using namespace std;
#define LL int long long
int a[305][305],asc[305][305],desc[305][305],decide[305]={0};
int bsearch(int *ss,int left,int  right,int element)
{
   if(right>=left)
   {
        int mid=left+(right-left)/2;
        if(ss[mid]>element) 
        	return bsearch(ss,left,mid-1,element);
        if(ss[mid]==element)  
        	return mid;
        return bsearch(ss,mid+1,right,element);
   }
   return -1;
}
int bsearch2(int *ss,int left,int  right,int element)
{
   if(right>=left)
   {
        int mid=left+(right-left)/2;
        if(ss[mid]<element) 
        	return bsearch2(ss,left,mid-1,element);
        if(ss[mid]==element)  
        	return mid;
        return bsearch2(ss,mid+1,right,element);
   }
   return -1;
}
int main()
{
	int n,i,j,k,ind,asc_ind,desc_ind,sa,sd,cost=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			asc[i][j]=a[i][j];
			desc[i][j]=a[i][j];
		}
		sort(asc[i]+1,asc[i]+n+1);
		sort(desc[i]+1,desc[i]+n+1,greater<int>());
	}
	for(i=1;i<=n;i++)
	{
		sa=0,sd=0;
		for(j=1;j<=n;j++)
		{
			asc_ind=bsearch(asc[i],1,n,a[i][j]);
			sa+=(int)pow((j-asc_ind),2);
			desc_ind=bsearch2(desc[i],1,n,a[i][j]);
			sd+=(int)pow((j-desc_ind),2);
		}
		//printf("sa=%d sd=%d\n",sa,sd);
		if(sa==sd)
		{
			cost+=sa;
			decide[i]=0;
		}
		else if(sa<sd)
		{
			cost+=sa;
			decide[i]=0;
		}
		else
		{
			cost+=sd;
			decide[i]=1;
		}
	}
	//printf("cost=%d\n",cost);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(decide[i]==0)
				printf("%d ",asc[i][j]);
			else
				printf("%d ",desc[i][j]);
		}
		printf("\n");
	}
} 