// _Z3dfsi minlen
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int K, N, R;

int minl[105][10005];
int totallen = 0;
int totalcost = 0;
int minlen = 1 << 30;
int visted[105];
struct road
{
	int  e, l, t;
	
};

vector<vector<road>>citymap(110);

void dfs(int s)
{
	if (s == N)
	{
		minlen = minlen < totallen ? minlen : totallen;
		return;
	}
	for (int i = 0; i < citymap[s].size(); i++)
	{ 
		int d = citymap[s][i].e;
		if (!visted[d])
		{
			int cost = totalcost + citymap[s][i].t;
			if (cost > K)continue;
			if (totallen + citymap[s][i].l >= minlen || totallen + citymap[s][i].l >= minl[d][cost])continue;
			totalcost += citymap[s][i].t;
			totallen += citymap[s][i].l;
			minl[d][cost] = totallen;
			visted[d] = 1;
			dfs(d);
			visted[d] = 0;
			totalcost -= citymap[s][i].t;
			totallen  -= citymap[s][i].l;
		}
	}
}
int main()
{

	cin >> K >> N >> R;
	
	for (int i = 0; i < R; i++)
	{
		int s; road r;
		cin >> s >> r.e >> r.l >>r.t;
		if (s != r.e)citymap[s].push_back(r);

	}
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 10005; j++)
			minl[i][j] = 1 << 30;
	memset(visted, 0, sizeof(visted));
	visted[1] = 1;
	dfs(1);
	if (minlen < (1 << 30))cout << minlen << endl;
	else cout << " -1" << endl;

}