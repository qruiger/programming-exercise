#include <bits/stdc++.h>
#define LL int long long
#define infinite LLONG_MAX
using namespace std;
LL sum;
class AdjListNode
{
    LL v;
    LL weight;
    public:
    AdjListNode(LL v1,LL w1)  
    { 
        v = v1;  
        weight = w1;
    }
    LL getV()       
    {  
        return v;  
    }
    LL getWeight()  
    {  
        return weight; 
    }
};
class Graph
{
    LL V;
    list<AdjListNode> *adj;
    void topologicalSortUtil(LL v,bool visited[],stack<LL> &Stack);
    public:
    Graph(LL V);   
    void addEdge(LL u,LL v,LL weight);
    void shortestPath(LL s);
};
Graph::Graph(LL V)
{
    this->V=V;
    adj=new list<AdjListNode>[V];
}
void Graph::addEdge(LL u,LL v,LL weight)
{
    AdjListNode node(v,weight);
    adj[u].push_back(node); 
}
void Graph::topologicalSortUtil(LL v,bool visited[],stack<LL> &Stack)
{
    visited[v]=true;
    list<AdjListNode>::iterator i;
    for (i=adj[v].begin();i!=adj[v].end();i++)
    {
        AdjListNode node=*i;
        if(!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    Stack.push(v);
}
void Graph::shortestPath(LL s)
{
    stack<LL> Stack;
    LL dist[V];
    bool *visited=new bool[V];
    for(LL i=0;i<V;i++)
        visited[i]=false;
    for(LL i=0;i<V;i++)
        if (visited[i]==false)
            topologicalSortUtil(i,visited,Stack);
    for(LL i=0;i<V;i++)
        dist[i]=infinite;
    dist[s]=0;
    while(Stack.empty()==false)
    {
        LL u=Stack.top();
        Stack.pop();
        list<AdjListNode>::iterator i;
        if(dist[u]!=infinite)
        {
          for(i=adj[u].begin();i!=adj[u].end();i++)
             if(dist[i->getV()]>dist[u]+i->getWeight())
                dist[i->getV()]=dist[u]+i->getWeight();
        }
    }
    for(LL i=0;i<V;i++)
    {
        if(dist[i]!=infinite && dist[i]!=0)
        {
            //printf("%lld ",dist[i]);
            sum+=dist[i];         
        }
    }
    //printf("\n");
}
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;
        LL n,wt,a[4][100005],k,i,j;
        scanf("%lld",&n);
        Graph g(n+1);
        for(i=1;i<=3;i++)
        {
            for(j=1;j<n;j++)
            {
                if(i+j<=n)
                {    
                    scanf("%lld",&a[i][j]);
                }
            }
        }
        for(j=1;j<n;j++)
        {
            k=j+1;
            for(i=1;i<=3;i++)
            {
                if(i+j<=n)
                {    
                    g.addEdge(j,k,a[i][j]);
                    k++;
                }
            }
        }
        for(i=1;i<n;i++)
        {
            g.shortestPath(i);
        }
        printf("%lld\n",sum);
    }
    return 0;
} 
