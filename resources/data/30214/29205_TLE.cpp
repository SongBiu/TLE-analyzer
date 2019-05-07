// _Z3dfsiii
#include <stdio.h>
#include <string.h>
int coins,cities,roads,cur_coins=0,cur_length=0,ans=99999,visited[101],num[101]={0};
struct point
{
	int d;
	int length;
	int cost;
}edge[101][10001];
void dfs(int k,int dis,int mon)
{
	if(mon>coins)return;
	if(k == cities)
	{
		if(dis< ans)
			ans = dis;
		return;
	}
	int i;
	for(i=0;i<num[k];i++ )
	{
		if(visited[edge[k][i].d] == 0 && cur_coins + edge[k][i].cost <= coins && cur_length + edge[k][i].length < ans)
		{
			visited[edge[k][i].d] = 1;
			dfs(edge[k][i].d,dis+edge[k][i].length,mon+edge[k][i].cost);
			visited[edge[k][i].d] = 0;
		}
	}
}

int main()
{
	int s, d, l, t, i;	
	scanf("%d%d%d",&coins, &cities, &roads);
	for(i=0; i<roads; i++)
	{
		scanf("%d %d %d %d", &s, &d, &l, &t);
		edge[s][num[s]].d = d;
		edge[s][num[s]].cost = t;
		edge[s][num[s]].length = l;
		num[s]++;
	}
	memset(visited, 0, sizeof(visited));
	visited[1] = 1;
	dfs(1,0,0);
	if(ans==99999)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}