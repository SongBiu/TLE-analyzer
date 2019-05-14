// _Z2goiii minlen
#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
struct Road
{
	int from, to, len, fee;
	Road() {}
	Road(int a, int b, int c, int d): from(a), to(b), len(c), fee(d) {}
	bool operator<(const Road& a) const
	{
		return from < a.from;
	}
}road[10000];
int minlen = 0x7fffffff;
int ncity, nroad;
bool visited[110];
void go(int nowcity, int money, int len)
{
	if(nowcity == ncity)
	{
		if(minlen > len)
			minlen = len;
		return;
	}
	if(len >= minlen)
		return;
	int bound = upper_bound(road, road+nroad, Road(nowcity, 0, 0, 0)) - road;
	for(int i = lower_bound(road, road+nroad, Road(nowcity, 0, 0, 0)) - road; i < bound; ++i)
	{
		if(!visited[road[i].to] && money >= road[i].fee)
		{
			visited[road[i].to] = true;
			go(road[i].to, money-road[i].fee, len+road[i].len);
			visited[road[i].to] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int money; 
	cin >> money >> ncity >> nroad;
	for(int i = 0; i < nroad; ++i)
		cin >> road[i].from >> road[i].to >> road[i].len >> road[i].fee;
	sort(road, road+nroad);
	visited[1] = true;
	go(1, money, 0);
	if(minlen == 0x7fffffff)
		cout << -1;
	else
		cout << minlen;
	return 0;
} 