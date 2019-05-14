// _Z3dfsi minlen
#include<iostream>
#include<vector>
using namespace std;
int K = 0, N = 0, R = 0;
int minlen = 0;
int nowlen = 0;//当前的路长
int nowtoll = 0;//当前费用
int besttoll[110][10010] = { 0 };//走到第几个城市，并且用了多少钱的时候的最短路径
int visited[110] = { 0 };
struct road
{
	int lenth;
	int toll;
	int terminate;
};
vector<vector<road> > citymap(110);
void dfs(int citynum)
{
	if (citynum == N && (nowlen < minlen || minlen == 0))
	{
		minlen = nowlen;
		return;
	}
	if (besttoll[citynum][nowtoll] > nowlen || besttoll[citynum][nowtoll] == 0)
		besttoll[citynum][nowtoll] = nowlen;
	for (int i = 0; i < citymap[citynum].size(); ++i)
	{
		if (!visited[citymap[citynum][i].terminate])
		{
			int cost = nowtoll + citymap[citynum][i].toll, len = nowlen + citymap[citynum][i].lenth;
			if (cost > K || (len > besttoll[citymap[citynum][i].terminate][cost] && besttoll[citymap[citynum][i].terminate][cost] != 0) || visited[citymap[citynum][i].terminate] || (len >= minlen && minlen != 0))
				continue;

			nowlen += citymap[citynum][i].lenth;
			nowtoll += citymap[citynum][i].toll;
			visited[citymap[citynum][i].terminate] = 1;
			dfs(citymap[citynum][i].terminate);
			nowlen -= citymap[citynum][i].lenth;
			nowtoll -= citymap[citynum][i].toll;
			visited[citymap[citynum][i].terminate] = 0;
		}
	}
	return;
}
int main()
{
	cin >> K >> N >> R;
	for (int i = 0; i < R; ++i)
	{
		int s;
		road temp;
		cin >> s >> temp.terminate >> temp.lenth >> temp.toll;
		citymap[s].push_back(temp);
	}
	dfs(1);
	if (minlen == 0)
		cout << -1;
	else
		cout << minlen;
	return 0;
}