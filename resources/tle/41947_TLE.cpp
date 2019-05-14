// _Z3dfsi minLen
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int K, N, R;    //K块钱，N个城市，R条路
struct Road
{
	int d, L, t;   //终点d，长度L，过路费t
};
vector< vector<Road> > G(110);    //G[i]表示从第i个城市 连接出去 的 所有路
int minLen, totalLen, totalCost;    //最小长度，当前路径的长度，当前路径的花费
short visted[110];     //visited[i]为0 表示第i个城市还没被访问
void dfs(int i)   //从第i个城市开始进行DFS
{
	if (i == N)
	{
		minLen = min(totalLen, minLen);
		return;
	}
	for (int j = 0; j < G[i].size(); ++j)   //遍历从城市i连出去的所有的路
	{
		Road r = G[i][j];
		if (totalCost + r.t > K)   //钱不够时，直接尝试下一条路
			continue;   
		if (!visted[r.d])    //该路的终点没有走过
		{
			if (totalLen + r.L >= minLen)   //当前的路在途中已经大于之前的最优路径，直接跳过
				continue;

			totalLen += r.L;			
			totalCost += r.t;
			visted[r.d] = 1;
			dfs(r.d);  
		//从r.d出发找路做完之后，会回到该循环尝试i的下一条路，而在试下一条路之前，需要撤销r.d被访问的标记
			visted[r.d] = 0;
			totalLen -= r.L;
			totalCost -= r.t;
		}
	}
}
int main()
{
	cin >> K >> N >> R;
	for (int i = 0; i < R; ++i)
	{
		int s;  Road r;           //s为起点
		cin >> s >> r.d >> r.L >> r.t;
		if (s != r.d)
			G[s].push_back(r);
	}
	memset(visted, 0, sizeof(visted));    //一开始全部没访问过
	totalLen = 0;  totalCost = 0;
	minLen = 1 << 30;
	visted[1] = 1;
	dfs(1);    //从城市1 开始出发找到 城市N 的最短的路
	if (minLen < (1 << 30))
		cout << minLen << endl;
	else
		cout << -1 << endl;
	return 0;
}