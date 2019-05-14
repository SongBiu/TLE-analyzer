// _Z3dfsi minLen
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int k,n,r;
struct Road{
	int d,l,t;//终点、长度、花费 
}; 
vector< vector< Road> > G(110);//邻接表 
int minLen;//目前最佳路径长度 
int totalLen;//正在探索的路长度 
int totalCost;//正在走的路的钱 
int visited[110];//是否走过城市 

void dfs(int s){
	if(s==n){//走到终点了 
		minLen=min(minLen,totalLen); //选择更小的 
		return ;
	}
	for(int i=0;i<G[s].size();i++){
		Road r=G[s][i];
		if(totalCost+r.t>k)continue;//判断钱是否够
		if(!visited[r.d]) {//要走这个r.d 
			totalLen+=r.l;
			totalCost+=r.t;
			visited[r.d]=1;
			dfs(r.d);
			totalLen-=r.l;
			totalCost-=r.t;
			visited[r.d]=0;
		}
		
	}
}
int main(){
	cin>>k>>n>>r;
	for(int i=0;i<r;i++){  //读取数据 
		int s;//边起点
		Road r;//边的信息
		cin>>s>>r.d>>r.l>>r.t;
		if(s!=r.d){
			G[s].push_back(r);//加入邻接表 
		} 
	} 
	memset(visited,0,sizeof(visited));//初始化标志为都没访问过
	totalLen=0;
	minLen=1<<30; //设一个大值 
	totalCost = 0;
	visited[1]=1;
	dfs(1);
	if(minLen<(1<<30)){
		cout<<minLen<<endl; 
	} else cout<<"-1"<<endl;
	 
	return 0;
}