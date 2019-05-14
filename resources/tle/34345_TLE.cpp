// _Z3Dfsi minLen
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <set>
#include <string>
#include <functional>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
//int K,N,R;
int S;//起点
int D;//终点
int L;//长度
int T;//钱数
int N;//城市编号
int R;//R条路
int K;//K块钱
struct Road {
	int d, L, t;
};
vector<vector<Road> > cityMap(110);//邻接表  cityMap[i]是从i点出发的路的集合
int minLen=1<<30;//当前的最优解
int totalLen;//现在走的这条路的长度（用于剪枝）
int totalCost;//正在走的路的花销
//int minL[110][10100];//minL[i][j]表示从1到i点的花销为j的最短路的长度   用于剪枝
bool visited[110];
void Dfs(int s){//从s出发{
	if(s==N){
		minLen=min(minLen,totalLen);
		return;
	}
	for(int i=0;i<cityMap[s].size();++i){
		int d=cityMap[s][i].d;
		if(!visited[d]){
			int cost=totalCost+cityMap[s][i].t;
			if(cost>K)
				continue;
			if (totalLen + cityMap[s][i].L >= minLen
					)
				continue;
			totalLen+=cityMap[s][i].L;
			totalCost=cost;

			visited[d]=1;
			Dfs(d);
			visited[d]=0;
			totalLen-=cityMap[s][i].L;//所有的都要回到原来的状态才能从原来的位置再次开始
			totalCost-=cityMap[s][i].t;
		}
	}
}
int main(){
	cin>>K>>N>>R;
	for(int i=0;i<R;++i){
		int s;
		Road r;
		cin>>s>>r.d>>r.L>>r.t;
		if(s!=r.d)
			cityMap[s].push_back(r);
	}

	memset(visited,0,sizeof(visited));
	totalLen=0;totalCost=0;visited[1]=1;
	Dfs(1);
	if(minLen<(1<<30))
		cout<<minLen<<endl;
	else
		cout<<"-1"<<endl;

}
