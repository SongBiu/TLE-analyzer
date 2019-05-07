// _Z3fi
#include <stdio.h>
#include <string.h>
#define N 110
#define M 10010
#define inf 0xfffffff
int coins, cities, roads;
int cur_coins, cur_length, ans;
int visited[N];
struct point
{
	int d;
	int length;
	int cost;
	struct point *next;
}*vert[N], edge[M];

void dfs(int k)
{
	struct point *p;

	if(k == cities)
	{
		if(cur_length < ans)
			ans = cur_length;
		return;
	}
	for(p=vert[k]; p!=NULL; p=p->next)
	{
		//没有访问过， 钱还够， 路没有比最短的长
		if(visited[p->d] == 0 && cur_coins + p->cost <= coins && cur_length + p->length < ans)
		{
			cur_length += p->length;
			cur_coins += p->cost;
			visited[p->d] = 1;
			dfs(p->d);
			visited[p->d] = 0;
			cur_length -= p->length;
			cur_coins -= p->cost;
		}
	}
}

int main()
{
	int s, d, l, t, i;
	scanf("%d", &coins);
	
		scanf("%d %d", &cities, &roads);
		for(i=0; i<N; i++)
			vert[i] = NULL;
		for(i=0; i<roads; i++)
		{
			scanf("%d %d %d %d", &s, &d, &l, &t);
			edge[i].d = d;
			edge[i].cost = t;
			edge[i].length = l;
			edge[i].next = vert[s];
			vert[s] = &edge[i];
		}
		cur_length = 0;
		cur_coins = 0;
		ans = inf;
		memset(visited, 0, sizeof(visited));
		visited[1] = 1;
		dfs(1);
		printf("%d\n", ans);
	return 0;
}
