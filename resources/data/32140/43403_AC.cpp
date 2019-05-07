// _Z3dfsiii
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
unsigned int K = 0;
int N = 0;
int R = 0;
int cost = 0x3fffffff;
int totaldis = 0x3fffffff;
class city_t {
public:
	int tcost;
	int tdis;
	int nroad;
	int roadlist[200];
	bool vis;
	city_t() {
		tcost = 0x3fffffff;
		tdis = 0x3fffffff;
		nroad = 0;
		vis = false;
	}
}city[101];
struct road_t {
	int s;
	int d;
	int l;
	int t;
	bool operator< (road_t a) {
		return this->l < a.l;
	}
}road[10001];
void dfs(unsigned int cityp,int tdistance,int ttoll) {
	if (ttoll > K || tdistance >= totaldis) {
		return ;
	}else if ((cityp == 1)) {
		if (tdistance < totaldis) {
			totaldis = tdistance;
			return ;
		}
		else {
			return ;
		}
	}
	for (int i = 0; i < city[cityp].nroad; i++) {
		if (city[road[city[cityp].roadlist[i]].s].vis == false) {
			city[road[city[cityp].roadlist[i]].s].vis = true;
			dfs(road[city[cityp].roadlist[i]].s, tdistance + road[city[cityp].roadlist[i]].l, ttoll + road[city[cityp].roadlist[i]].t);
			//if(ret > 0)
			city[road[city[cityp].roadlist[i]].s].vis = false;
		}
	}
	return ;
}
int main() {
	cin >> K >> N >> R;
	for (int i = 0; i < R; i++) {
		//cin >> road[i].s >> road[i].d >> road[i].l >> road[i].t;
		scanf("%d %d %d %d", &road[i].s, &road[i].d, &road[i].l, &road[i].t);
	}
	sort(road, road + R);
	for (int i = 0; i < R; i++) {
		city[road[i].d].roadlist[city[road[i].d].nroad++] = i;
	}
	dfs(N, 0, 0);
	if (totaldis!= 0x3fffffff)
		cout << totaldis << endl;
	else
		cout << "-1" << endl;
	//system("pause");
	return 0;
}