// _Z3dfsi minLen
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Road                  //存放一条路（边）的信息 
{
	int d;                   //这条路的终点（起点不需要存） 
	int l;                   //长度 
	int t;                   //过路费 
}; 
vector <vector<Road> > G(110);//邻接表（数组套数组）存整个图，110行，每一行都是Road对象 "G[i]"存放从节点i出发的边 
int K,N,R;                   //三个变量分别记录钱数、城市数、道路数 
int minLen;                  //记录最短路径
int totalLen;                //记录当前路径长度
int totalCost;               //记录当前路过路费
int visited[110];            //记录城市是否走过(1-已走过 0-未走过)
void dfs(int s)              //从s点出发深度优先搜索
{
	int i;
	if(s==N)                 //走到终点 
	{
		minLen=min(minLen,totalLen);
		return;
	}
	//注意从s点出发有多条路，遍历 
	for(i=0;i<G[s].size();i++)
	{
		Road r=G[s][i];       //从s出发的边i 
		if(totalCost+r.t>K)   //钱不够，无法通行 
			continue;
		if(!visited[r.d])     //城市r.d未走过 
		{
			totalLen+=r.l;
			totalCost+=r.t;
			visited[r.d]=1;
			dfs(r.d);         //从r.d出发继续找路
			visited[r.d]=0;   //试其他路径
			totalLen-=r.l;     
			totalCost-=r.t;
		}
	}
} 
int main()
{
	int i; 
	while(cin>>K>>N>>R)
	{
		for(i=0;i<R;i++)     //读入R条路 
		{
			int s;           //s表示路的起点	
			Road r;          //存放路的信息 
			cin>>s>>r.d>>r.l>>r.t;
			if(s!=r.d)       //不考虑起点等于终点的路 
				G[s].push_back(r); //新读入一条边r，放到G[s]一维数组内，即从节点s出发的边 
		} 
		memset(visited,0,sizeof(visited)); //初始化信息 
		totalLen=0;
		minLen=1<<30;
		totalCost=0;
		visited[i]=1;        //从1号点开始dfs 
		dfs(1); 
		if(minLen<(1<<30))
			cout<<minLen<<endl;
		else
			cout<<"-1"<<endl; 
	}
	return 0;
}