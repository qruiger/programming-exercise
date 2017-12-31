#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL int long long
LL a[50005],n,maxindex,smaxindex,maxval=0,smaxval=0,m=0,ind;
struct node
{
	LL dest;
	struct node* next;
};
struct list
{
	struct node* head;
};
struct graph
{
	LL v;
	struct list *array;
};
struct node* newnode(LL dest)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->dest=dest;
	new_node->next=NULL;
	return new_node;
}
struct graph* creategraph(LL v)
{
	struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    	g->v=v;
    	g->array=(struct list*)malloc(v*sizeof(struct list));
    	LL i;
    	for (i=1;i<=v;i++)
        	g->array[i].head=NULL;
    	return g;
}
void addedge(struct graph* g, LL src, LL dest)
{
	struct node* newNode=newnode(dest);
	newNode->next=g->array[src].head;
	g->array[src].head=newNode;
	newNode=newnode(src);
	newNode->next=g->array[dest].head;
	g->array[dest].head=newNode;
}
void print(struct graph* g)
{
    LL i,j,temp[50005]={0};
    for (i=1;i<=g->v;i++)    
    {
        struct node* p=g->array[i].head;
        struct node* q;
        q=p;
        temp[i]++;
        while(p)
        {
            temp[p->dest]++;
            p=p->next;
        }
        m=0;
        for(j=1;j<=n;j++)
        {
		if(temp[maxindex]==0 && i!=maxindex)
		{
			ind=maxindex;
			break;
		}
		if(temp[maxindex]==1 && temp[smaxindex]==0 && i!=smaxindex)
		{
			ind=smaxindex;
			break;
		}
		if(temp[j]!=1 && i!=j)
		{	
			if(m<a[j])
			{
				m=a[j];
				ind=j;
				if(m==maxval)
				{
					break;
				}
			}
		}
        }
        printf("%lld ",ind);
        temp[i]=0;
        while(q)
        {
            temp[q->dest]=0;
            q=q->next;
        }
    }
}  
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL i,c[50005]={0},flag=0,v,u;
		maxval=0,smaxval=0,m=0;
		scanf("%lld",&n);
		struct graph* g = creategraph(n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(maxval<a[i])
			{
				smaxval=maxval;
				smaxindex=maxindex;
				maxval=a[i];
				maxindex=i;
			}
			if(a[i]>smaxval && a[i]!=maxval)
			{
				smaxval=a[i];
				smaxindex=i;
			}
		}
		for(i=1;i<n;i++)
    		{
    			scanf("%d %d",&v,&u);
    			c[v]++;
			c[u]++;
    			addedge(g,v,u);
    		}
    		for(i=1;i<=n;i++)
		{
			if(c[i]==n-1)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			printf("0\n");
			continue;
		}
		print(g);
		printf("\n");
	}
	return 0; 
}  
