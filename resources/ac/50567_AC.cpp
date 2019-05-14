// _Z3Dfsi minLen
//8.3.POJ 1742 ROADS
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int K,N,R;

struct Road {
	int d, L, t;// 终点d,长度L,过路费t
};
//邻接表, cityMap[i]是从i点有路连到的城市的集合
vector <vector<Road> >cityMap(110);

int minLen=1<<30;    //目前最优路径的长度
int totalLen;        //正在走的路径的长度
int totalCost;       //正在走的路径的花销
int visited[110];    //城市是否走过的标记
int minL[110][10100];//minL[i][j]表示从1到i点，花销为j的最短路的长度

void Dfs(int s) {    //从s开始向N行走
	if(s==N) {
		minLen=min(minLen,totalLen);
		return;
	}
	for(int i=0; i<cityMap[s].size(); i++) {
		//逐个考察s 右路连到的点
		int d=cityMap[s][i].d; //s有路连到d
		if(!visited[d]){
			int cost=totalCost+cityMap[s][i].t;
			if(cost>K) //钱花超了
				continue;
			if(totalLen+cityMap[s][i].L>=minLen 
			|| totalLen+cityMap[s][i].L>=minL[d][cost]
				)
				continue; //基本最优性剪枝和处处最优剪枝
			totalLen+=cityMap[s][i].L;
			totalCost+=cityMap[s][i].t;
			minL[d][cost]=totalLen;
			visited[d]=1;
			Dfs(d);
			visited[d]=0;
			totalCost-=cityMap[s][i].t;
			totalLen-=cityMap[s][i].L; 
		} 
	}
}

int main() {
//	freopen("in.txt","r",stdin);
	cin>>K>>N>>R;
	for(int i=0; i<R; i++){
		int s;
		Road r;
		cin>>s>>r.d>>r.L>>r.t;
		if(s!=r.d)
			cityMap[s].push_back(r);
	}
	for(int i=0; i<110; i++)
		for(int j=0; j<10100; j++)
			minL[i][j]=1<<30;
	memset(visited,0,sizeof(visited));
	totalLen=0;
	totalCost=0;
	visited[1]=1;
	minLen=1<<30;
	Dfs(1);
	if(minLen<(1<<30))
		cout<<minLen<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}
