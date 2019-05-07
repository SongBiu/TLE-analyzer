// _Z3dfsiii
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

void addedges(int u,int v,int dis,int cost)
{
	node *p=++New;
	p->v=v;
	p->dis=dis;
	p->cost=cost;
	p->next=adj[u];
	adj[u]=p;
}

int K,N,M;
int dp[MAXN+10][MAXK+10];
int ans=INF;
int shortest[MAXN+10];
bool vis[MAXN+10];

void dijkstra(int begin)
{
	shortest[begin]=0;
	vis[begin]=1;
	
	for(int i=1;i<=N;++i)
	{
		int Dmin=-INF,pos=-1;
		for(int j=1;j<=N;++j)
			if(!vis[j]&&shortest[j]<Dmin)
			{
				Dmin=shortest[j];
				pos=j;
			}
		
		vis[pos]=1;
		
		for(node *p=adj[pos];p!=NULL;p=p->next)
			shortest[p->v]=min(shortest[p->v],shortest[pos]+p->dis);
	}
}

void dfs(int u,int res,int far)
{
	if(dp[u][res]<=far)
		return;
	else dp[u][res]=far;
	
	if(u==N)
	{
		ans=min(ans,dp[u][res]);
		return;
	}
	
	for(node *p=adj[u];p!=NULL;p=p->next)
		if(res>=p->cost&&far+shortest[u]<ans)dfs(p->v,res-p->cost,far+p->dis);
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
	}
	
	memset(dp,0x3f,sizeof(dp));
	dfs(1,K,0);
	
	output();
}