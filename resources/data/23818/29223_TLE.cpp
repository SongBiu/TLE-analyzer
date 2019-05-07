#include <iostream>
using namespace std;

int road_num, city_num, money, min_length = 0;

class Croad
{
public:
	int s;
	int d;
	int l;
	int c;
	bool flag;                        //是否可以继续走
}road[10001];

void guess(int t, int left_cost, int len)       //抵达城市t,剩余left_cost，已走len;
{
	if(t == city_num)
	{
		if(min_length == 0 || min_length > len)
			min_length = len;
		return;
	}
	if(len > min_length && min_length != 0)
		return;
	for(int i = 1; i <= road_num; i++)
	{
		if(road[i].s == t && road[i].flag && left_cost >= road[i].c)
		{
			road[i].flag = false;
			guess(road[i].d, left_cost - road[i].c, len + road[i].l);
			road[i].flag = true;
		}
	}
}

int main()
{
	cin >> money >> city_num >> road_num;
	for(int i = 1; i <= road_num; i++)
	{
		cin >> road[i].s >> road[i].d >> road[i].l >> road[i].c;
		road[i].flag = true;
	}
	guess(1, money, 0);
	cout << min_length << endl;
	return 0;
}