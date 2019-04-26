#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int,int> P;
const int N = 100;
const int Inf = 0x7fffffff;
struct Node
{
    int v,l,t;
    Node(int a=0,int b=0,int c=0):v(a),l(b),t(c){}
};
vector<Node> Map1[N+1],Map2[N+1];
int k,n,Mincost[N+1],Minlen[N+1];
int answer;
bool vis[N+1];
void Dijkstra()
{
    for(int i=1;i<n;++i) Mincost[i] = Inf;
    Mincost[n] = 0;
    priority_queue<P,vector<P>,greater<P> > pq;
    pq.push(P(0,n));
    while(!pq.empty())
    {
        int cost = pq.top().first,v = pq.top().second;
        pq.pop();
        if(cost != Mincost[v]) continue;
        for(int i=0;i<Map2[v].size();++i)
        {
            if(Mincost[Map2[v][i].v] > cost+Map2[v][i].t)
            {
                Mincost[Map2[v][i].v] = cost+Map2[v][i].t;
                pq.push(P(Mincost[Map2[v][i].v],Map2[v][i].v));
            }
        }
    }
    for(int i=1;i<n;++i) Minlen[i] = Inf;
    Minlen[n] = 0;
    pq.push(P(0,n));
    while(!pq.empty())
    {
        int len = pq.top().first,v = pq.top().second;
        pq.pop();
        if(len != Minlen[v]) continue;
        for(int i=0;i<Map2[v].size();++i)
        {
            if(Minlen[Map2[v][i].v] > len+Map2[v][i].l)
            {
                Minlen[Map2[v][i].v] = len+Map2[v][i].l;
                pq.push(P(Minlen[Map2[v][i].v],Map2[v][i].v));
            }
        }
    } 
}
void Dfs(int u,int len,int cost)
{
     if(len+Minlen[u]>=answer || cost+Mincost[u]>k) return;
     if(u == n)
     {
         answer = len;
         return;
     }
     for(int i=0;i<Map1[u].size();++i)
     {
         if(!vis[Map1[u][i].v])
         {
             vis[Map1[u][i].v] = true;
             Dfs(Map1[u][i].v,len+Map1[u][i].l,cost+Map1[u][i].t);
             vis[Map1[u][i].v] = false;       
         }
     }
}
int main()
{
    int r,s,d,l,t;
    scanf("%d%d%d",&k,&n,&r);
    for(int i=0;i<r;++i)
    {
        scanf("%d%d%d%d",&s,&d,&l,&t);
        Map1[s].push_back(Node(d,l,t));
        Map2[d].push_back(Node(s,l,t));
    }
    Dijkstra();
    answer = Inf;
    vis[1] = true;
    Dfs(1,0,0);
    if(answer == Inf)    printf("-1\n");
    else                 printf("%d\n",answer);
    return 0;
}