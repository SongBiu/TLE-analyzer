// _Z3dfsi minLen
#include<iostream>
#include<vector>
#include<cstring>
using namespace std; 

struct Road{
int d,len,cost;
};
vector<vector<Road>> cityMap(110);//保存图结构
int K,R,N;
int totalCost=0;
int totalLen=0;//当前已经走了多少len
int minLen=1<<30;//用于最优性剪枝 1<<30表示1左移30位，每左移1位乘以2，所以就是1*2^30
int visited[110];//dfs常用的结构 保存是否访问的状态
int minL[110][10100];//用于处处最优剪枝

void dfs(int s){
	//从s出发 dfs找到能够达到的最优路径 长度保存在minLen中
	if(s==N){
		minLen=min(minLen,totalLen);
		return;
	}
	for(int i=0;i<cityMap[s].size();i++){
		int d=cityMap[s][i].d;
		if(!visited[d]){
			int cost=cityMap[s][i].cost+totalCost;
			int len=totalLen+cityMap[s][i].len;
			if(cost>K){
				continue;
			}
			if(len>=minLen||len>=minL[d][cost])
				continue;
			totalLen=len;
			totalCost+=cityMap[s][i].cost;
			minL[d][cost]=totalLen;
			visited[d]=1;
			dfs(d);
			visited[d]=0;
			totalLen=totalLen-cityMap[s][i].len;
			totalCost-=cityMap[s][i].cost;
		}
	}

}
int main(){
	cin>>K>>N>>R;
	for(int i=0;i<R;i++){
		int s;
		Road r;
		cin>>s>>r.d>>r.len>>r.cost;
		cityMap[s].push_back(r);
	}
	memset(visited,0,sizeof(visited));
	for(int i=0;i<110;i++){
		for(int j=0;j<10100;j++){
			minL[i][j]=1<<30;
		}
	}
	visited[1]=0;
	dfs(1);
	if(minLen<(1<<30)){
		cout<<minLen<<endl;
	}else{
		cout<<"-1"<<endl;
	}
	


}