// _Z3dfsi minlen
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int K,N,R,minlen,totallen,totalcost;
struct road
{
	int e,l,c;
};
vector<vector<road> >map(110);
int mem[110][10100];
int flag[110];
void dfs(int n)
{
	if (n == N)
	{
		minlen = min(minlen, totallen);
		return;
	}
	for (int i = 0; i < map[n].size(); ++i)
	{
		int d = map[n][i].e;
		if (flag[d])
			continue;
		int cost = totalcost + map[n][i].c;
		if (totallen >= mem[n][cost])
			continue;
		if (cost > K)
			continue;
		if (totallen + map[n][i].l >= minlen)
			continue;
		totallen += map[n][i].l;
		totalcost = cost;
		flag[d] = 1;
		mem[n][cost] = totallen;
		dfs(d);
		flag[d] = 0;
		totalcost -= map[n][i].c;
		totallen -= map[n][i].l;
	}
}
int main(int argc, char const *argv[])
{
	int i,s;
	road temp;
	cin >> K >> N >> R;
	for (i = 0; i < R; ++i)
	{
		cin >> s >> temp.e >> temp.l >> temp.c;
		map[s].push_back(temp); 
	}
	memset(flag,0,sizeof(flag));
	for (i = 0; i < 110; ++i)
		for (int j = 0; j < 10010; ++j)
			mem[i][j] = 1 << 30;
	minlen = 1 << 30;
	totallen = totalcost = 0;
	dfs(1);
	if (minlen == 1 << 30)
		cout << -1;
	else
		cout << minlen;
	return 0;
}