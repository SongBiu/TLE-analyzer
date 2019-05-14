// _Z3dfsi minLen
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;
int K, N, R, S, D, L, T;
struct Road
{
	int d, L, t;
};

vector<vector<Road> > cityMap(110); // 邻接表，cityMap[i]是从点i有路连到的城市的集合
int minLen = 1 << 30;
int totalLen;
int totalCost;
int visit[110];
int minL[110][10100]; // minL[i][j]表示从1到i点的，花销为j的最短路的长度

void dfs(int s) // 从s开始向N走
{
	if(s == N)
	{
		minLen = min(minLen, totalLen);
		return;
	}
	for (int i = 0; i < cityMap[s].size(); ++i)
	{
		int d = cityMap[s][i].d;
		if (!visit[d])
		{
			int cost = totalCost + cityMap[s][i].t;
			if (cost > K)
				continue;
			if (totalLen+cityMap[s][i].L >= minLen || totalLen + cityMap[s][i].L >= minL[d][cost])
				continue;
			totalLen += cityMap[s][i].L;
			totalCost += cityMap[s][i].t;
			minL[d][cost] = totalLen;
			visit[d] = 1;
			dfs(d);
			visit[d] = 0;
			totalCost -= cityMap[s][i].t;
			totalLen -= cityMap[s][i].L;
		}
	}
}
int main()
{
	cin >> K >> N >> R;
	for (int i = 0; i < R; ++i)
	{
		int s;
		Road r;
		cin >> s >> r.d >> r.L >> r.t;
		if (s != r.d)
			cityMap[s].push_back(r);
	}
	for (int i = 0; i < 110; ++i)
		for (int j = 0; j < 10100; ++j)
			minL[i][j] = 1 << 30;
	memset(visit, 0, sizeof(visit));
	totalLen = 0;
	totalCost = 0;
	visit[1] = 1;
	minLen = 1 << 30;
	dfs(1);
	if (minLen < (1 << 30))
		cout << minLen << endl;
	else
		cout << -1 << endl;
	return 0;
}