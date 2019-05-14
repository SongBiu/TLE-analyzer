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

//优化而进行的数组
int minL[110][10010];   //minL 意思是到达第i个城市并且刚好花费j元时 的最小路径长度
						/*不如有一条路径过x点花了y元 另一条路也过x点 但到x点时也花了y元 这是如果后者的totalLen
							大于前者了 那么就没有继续下去的必要了 因为都花了y元到x点 后者走的路更长*/ 

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
			//进行剪枝 可以优化时间 、
			//当到达这里时的长度 已经比最小的路径长度都长或者等了 就没有继续下去的必要了 
			if(totalLen+r.l>=minLen)
				continue;
				
			if(totalLen+r.l>=minL[r.d][totalCost+r.t])
				continue;
			
			minL[r.d][totalCost+r.t]=totalLen+r.l;
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
	
	for(int i=0;i<110;i++)
		for(int j=0;j<10010;j++)
			minL[i][j]=1<<30;					
	
	minLen=1 << 30;      //很大的一个数 1左移30位 很大
	totalLen=0;
	totalCost=0;
	
	//在1号城市 所以1号是默认访问过了
	visit[1]=1; 
	dfs(1);
	
	if(minLen >= (1 << 30)) 
		cout<<"-1"<<endl;
	else 
		cout<<minLen<<endl;
	return 0;
}