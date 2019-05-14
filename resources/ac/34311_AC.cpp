// _Z8FindRoadiii Min
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define maxn 100
#define inf (1 << 31) - 1

struct road
{
	int d, l, t;
	road(int _d, int _l, int _t):d(_d), l(_l), t(_t){}
};

vector<road> city[maxn+10];
int K, N, R;
int _s, _d, _l, _t;
int passed[maxn+10];
int Min = inf;
int flag[maxn+10][maxn+10];

void FindRoad(int c, int m, int f)
{  
	if(c == N)
	{
		Min = min(f, Min);
		return;
	}
	if(f >= Min)
		return;
	if(flag[c][m] != -1 && flag[c][m] < f)
		return;
	flag[c][m] = f; 
	vector<road>::iterator p;	
	for(p = city[c].begin(); p != city[c].end(); ++p)
	{
		if(!passed[p->d] && m >= (p->t))
		{
			passed[p->d] = 1;
			FindRoad(p->d, m-(p->t), f+p->l);
			passed[p->d] = 0;
		}
	}
}

int main()
{
	scanf("%d%d%d", &K, &N, &R);
	memset(flag, -1, sizeof(flag));
	for(int i = 1; i <= R; ++i)
	{
		scanf("%d%d%d%d", &_s, &_d, &_l, &_t);
		city[_s].push_back(road(_d, _l, _t));
	}
	passed[1] = 1;
	FindRoad(1, K, 0);
	if(Min == inf)
		Min = -1;
	printf("%d\n", Min);
	return 0;
}