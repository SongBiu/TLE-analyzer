// _Z3dfsi minLen
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

struct Rode{            //这个结构体就是某一条路  是从某一个城市延伸出来的  
	int d,l,t;          //d是终点 l是长度 t路费 
};

int visit[110];         //标记数组 
vector< vector<Rode > > G(110);      //可以理解为二维数组 总共有110行 每一行代表了一个城市 这个城市是有不同多条路 所以也是个vector
									//比如 G[1][2]就表示城市1的第二条路
int minLen;             //最短路径的长度 
int totalLen;           //当前路径的长度 
int K;                  //总共有k元钱 
int totalCost;          //当前花费 
int N;                  //城市数
int R;                  //道路数 

void dfs(int s)         //以s城市为起点 走到N  
{
	//边界条件 
	if(s==N)
	{
		minLen=min(minLen,totalLen);  //就选一个较小的 
		return;	
	} 
	
	//遍历s城市的所有道路  依次以周围的道路为下一个城市
	for(int i=0;i<G[s].size();i++)	
	{
		Rode r=G[s][i];
		
		//先看路费够不够 
		if(totalCost+r.t>K) 
			continue;
		
		if(!visit[r.d])      //没有被访问过 
		{
			visit[r.d]=1;
			totalLen+=r.l;
			totalCost+=r.t;
			dfs(r.d);
			
			//出来后 回继续遍历其他路 意思是下一条路不选r  而是选另外的  所以应该把改变的状态变回来
			visit[r.d]=0;
			totalLen-=r.l;
			totalCost-=r.t; 
		} 
	}
				 
}

int main()
{
	cin>>K>>N>>R;
	for(int i=0;i<R;i++)  //把R条路输入 
	{
		Rode r;           //建立一个结构体 路 
		int s;            //起点标号 
		cin>>s>>r.d>>r.l>>r.t; 
		G[s].push_back(r);  //直接这样引入 第s个城市的某一条路的引入 
	} 
	memset(visit,0,sizeof(visit));
	
	minLen=1 << 30;      //很大的一个数 1左移30位 很大
	totalLen=0;
	totalCost=0;
	dfs(1);
	
	if(minLen >= (1 << 30)) 
		cout<<"-1"<<endl;
	else 
		cout<<minLen<<endl;
	return 0;
}