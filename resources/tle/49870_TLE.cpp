// _Z3dfsi minLen
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int K,N,R;//钱数、城市数、道路数
struct Road{
	int d,L,t;
}; 
vector< vector<Road> > G(110);
int minLen;//当前找到的最优路径的长度 
int totalLen;//正在走的路径长度
int totalCost;//正在走的路径的花销 
int visited[110];
void dfs(int s)   //从s点出发进行深度优先搜素 
{
	if(s == N) //判断是否走到终点
	{
		minLen = min(minLen,totalLen);
		return ; 
	} 
	for(int i = 0;i < G[s].size(); i++)
	{
		Road r = G[s][i];
		if(totalCost + r.t > K)
			continue;//表示钱不够，试下一条边
		if(!visited[r.d]) //判断r.d是否走过
		{
				totalLen += r.L;
				totalCost += r.t;
				visited[r.d] = 1;
				dfs(r.d);          //从r.d进行深度优先搜素,
				visited[r.d] = 0;   //从r.d深度优先搜素后, 则会回到循环试下一条路,所以要撤销对r.d的操作 
				totalLen -= r.L;
				totalCost -= r.t;
		} 				   
		
	}
} 
int main()
{
	cin >> K >> N >> R;
	for(int i = 0;i < R; i++)
	{
		int s;
		Road r;
		cin>>s>>r.d>>r.L>>r.t;
		if(s!=r.d)
		{
			G[s].push_back(r);
		}
	}
	memset(visited,0,sizeof(visited));
	totalLen = 0;
	minLen = 1<<30;
	totalCost = 0;
	visited[1] = 1;
	dfs(1);
	if(minLen < (1<<30))
		cout<<minLen<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}