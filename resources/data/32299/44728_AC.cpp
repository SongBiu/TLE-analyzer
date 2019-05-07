#include <cstdio>
#include <cstring>
#define N 110
#define M 10010
#define INF 0x3f3f3f3f

int head[N];
struct edge
{
    int u,v,w,c,next;
}e[M];
int cost,n,m,tot;
int d[N][M];

void add(int u , int v , int w , int c)
{
   e[tot].u = u; e[tot].v = v; e[tot].w = w; e[tot].c = c;
   e[tot].next = head[u]; head[u] = tot++;
}

void dfs(int u ,int c)
{
    if(d[u][c] != -1) return ;
    d[u][c] = INF;
    for(int k=head[u]; k!=-1; k=e[k].next)
    {
        int v = e[k].v;
        int w = e[k].w;
        int cc = e[k].c;
        if(c - cc >= 0)
        {
            dfs(v,c-cc);
            if(d[v][c-cc]+w < d[u][c])
                d[u][c] = d[v][c-cc]+w;
        }
    }
}

int main()
{
    scanf("%d%d%d",&cost,&n,&m);
    memset(head,-1,sizeof(head));
    tot = 0;
    while(m--)
    {
        int u,v,w,c;
        scanf("%d%d%d%d",&u,&v,&w,&c);
        add(v,u,w,c); //逆向建图，为了逆向DP
    }
    memset(d,-1,sizeof(d));
    for(int i=0; i<=cost; i++) d[1][i] = 0;
    int res = INF;
    for(int i=0; i<=cost; i++)
    {
        dfs(n,i);
        if(d[n][i] < res) 
            res = d[n][i];
    }
    if(res == INF) printf("-1\n");
    else           printf("%d\n",res);
}