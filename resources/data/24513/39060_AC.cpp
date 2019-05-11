// _Z3dfsiii ans
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MAXN 100
#define MAXM 10000
#define MAXK 10000
#define INF 0x3f3f3f3f
typedef long long int LL;

struct node
{
	int v,dis,cost;
	node *next;
}*adj[MAXN+10],Edges[MAXM+10],*New=Edges;

node *adj_[MAXN+10],Edges_[MAXM+10],*New_=Edges_;

void addedges(int u,int v,int dis,int cost)
{
	node *p=++New;
	p->v=v;
	p->dis=dis;
	p->cost=cost;
	p->next=adj[u];
	adj[u]=p;
}

void addedges_(int u,int v,int dis,int cost)
{
	node *p=++New_;
	p->v=v;
	p->dis=dis;
	p->cost=cost;
	p->next=adj_[u];
	adj_[u]=p;
}

int K,N,M;
int dp[MAXN+10][MAXK+10];
int ans=INF;
int shortest[MAXN+10];
int lowest[MAXN+10];
bool vis[MAXN+10];

void dijkstra_dis(int begin)
{
	memset(vis,0,sizeof(vis));
	memset(shortest,0x3f,sizeof(shortest));
	
	shortest[begin]=0;
	
	for(int i=1;i<=N;++i)
	{
		int Dmin=INF,pos=-1;
		for(int j=1;j<=N;++j)
			if(!vis[j]&&shortest[j]<Dmin)
			{
				Dmin=shortest[j];
				pos=j;
			}
		
		vis[pos]=1;
		
		for(node *p=adj_[pos];p!=NULL;p=p->next)
			shortest[p->v]=min(shortest[p->v],shortest[pos]+p->dis);
	}
}

void dijkstra_cost(int begin)
{
	memset(vis,0,sizeof(vis));
	memset(lowest,0x3f,sizeof(lowest));
	
	lowest[begin]=0;
	
	for(int i=1;i<=N;++i)
	{
		int Cmin=INF,pos=-1;
		for(int j=1;j<=N;++j)
			if(!vis[j]&&lowest[j]<Cmin)
			{
				Cmin=lowest[j];
				pos=j;
			}
		
		vis[pos]=1;
		
		for(node *p=adj_[pos];p!=NULL;p=p->next)
			lowest[p->v]=min(lowest[p->v],lowest[pos]+p->cost);
	}
}

void dfs(int u,int res,int far)
{
	if(dp[u][res]<=far)
		return;
	else dp[u][res]=far;
		
	if(far+shortest[u]>=ans)return;
	if(lowest[u]>res)return;
	
	if(u==N)
	{
		ans=min(ans,dp[u][res]);
		return;
	}
	
	for(node *p=adj[u];p!=NULL;p=p->next)
		if(res>=p->cost)dfs(p->v,res-p->cost,far+p->dis);
}

void output()
{
	printf("%d\n",ans<INF?ans:-1);
}

int main()
{
	scanf("%d%d%d",&K,&N,&M);
	int i,j,a,b,c,d;
	
	for(i=1;i<=M;++i)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		addedges(a,b,c,d);
		addedges_(b,a,c,d);
	}
	
	dijkstra_dis(N);
	dijkstra_cost(N);
	
	memset(dp,0x3f,sizeof(dp));
	dfs(1,K,0);
	
	output();
}

/*
1
3
4
1 2 1 1
2 3 10 0
1 3 50 0
2 1 1 0
*/