// _Z7ds_pathi len_min
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;
#define inf 200
typedef struct {
	int src=-1, des=-1, len= inf, toll= inf;
}Edge;

Edge* getIns_edge(int src,int des,int len,int toll) {
	Edge* edge = (Edge*)malloc(sizeof(Edge));
	edge->src = src;
	edge->des = des;
	edge->len = len;
	edge->toll = toll;
	return edge;
}
//static Edge matrix[101][101];//点从1开始计数
static vector<Edge> adjac_list[101];
static int sign[101];//标记目前走过的点
static int k, n, r;
static int len_min = 1500000;
static int len_path=0;
void ds_path(int src) {
	if (sign[src] == 1)return;
	if (src == n) {//如果抵达目的，比较路径长
		len_min = min(len_path, len_min);
	}
	sign[src] = 1;//标记走过这个点

	for (int i = 0; i < adjac_list[src].size(); ++i) {
		int toll = adjac_list[src][i].toll;
		if (toll > k)continue;//剪枝，如果盘缠不够直接回溯找下一条路
		int len = adjac_list[src][i].len;
		k -= toll;
		len_path += len;
		if (len_path > len_min) {//剪枝，这条路已经大于当前最小路径,回溯
			k += toll;
			len_path -= len;
			continue;
		}
		ds_path(adjac_list[src][i].des);//以可达点作为新的源递归
									//回溯
		k += toll;
		len_path -= len;
	}
	sign[src] = 0;//*取消标记
}
int main() {
	cin >> k; cin >> n; cin >> r;
	for (int i = 0; i < r; ++i) {
		int src, des, len, toll;
		cin >> src; cin >> des; cin >> len; cin >> toll;
		Edge edge = *getIns_edge(src, des, len, toll);
		adjac_list[src].push_back(edge);
	}

	//输入完毕，开始深搜
	memset(sign, 0, sizeof(sign));
	ds_path(1);

	if (len_min == 1500000)cout << -1 << endl;
	else cout << len_min<<endl;
	system("pause");
	return 0;
}