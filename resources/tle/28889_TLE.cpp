// _Z5checkiii minnum
#include<iostream>
using namespace std;
struct Road
{
	int s, d, l, t;
};
Road road[10000];
int minnum = 1000000, n, r, k, state[101] = {0}, count[101] = {0}, head[101][101];
bool check(int , int, int);

int main()
{
	cin >> k >> n >> r;
	for (int i = 0; i < r; i++)
	{
		cin >> road[i].s >> road[i].d >> road[i].l >> road[i].t;
		head[road[i].s][count[road[i].s]++] = i;
	}
	if (check(1, 0, k))
		cout << minnum << endl;
	else
		cout << "-1" << endl;
	return 0;
}
bool check(int city, int dis, int left)
{
	if (state[city])
		return false;
	if (dis >= minnum)
		return false;
	if (left < 0)
		return false;
	if (city == n)
	{
		if (dis < minnum)
			minnum = dis;
		return true;
	}
	state[city] = 1;
	int i;
	bool flag = false;
	for (i = 0; i < count[city]; i++)
		if (road[head[city][i]].s == city)
		{
			if (check(road[head[city][i]].d, dis + road[head[city][i]].l, left - road[head[city][i]].t))
				flag = true;
		}
	state[city] = 0;
	return flag;
}
