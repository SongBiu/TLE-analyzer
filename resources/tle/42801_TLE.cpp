// _Z3DFSiii minL
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct road{
	int end;
	int length;
	int cost;
};//注意假如做邻接表的话要编的结构体
//不同于邻接矩阵，邻接表没有终点的信息，所以要存在结构体里。
int K,N,R;
vector<vector<road> > map(110);//要知道这些容器的初值化！
int minL=1<<30;
int midL[120][10010]={0};//注意要是二维
int used[110]={0};
void DFS(int s,int cost,int len){  
	if(cost>K)//这个必须在第一个就进行判断
		return ;
	//midL[s][cost]=min(midL[s][cost],len);
	if(s==N)
	{
		minL=min(minL,len);
	}
	for(int i=0;i<map[s].size();++i)
	{
		road temp=map[s][i];
		if(!used[temp.end])
		{
			//剪枝部分

			if(len+temp.length>=minL)
				continue;
			//if(len+temp.length>=midL[temp.end][temp.cost+cost])
			//	continue;
			used[temp.end]=1;
			DFS(temp.end,cost+temp.cost,len+temp.length);
			used[temp.end]=0;
		}
	}
}
int main(){
	cin>>K>>N>>R;
	for(int i=0;i<R;++i)
	{
		int s;
		road temp;
		cin>>s>>temp.end>>temp.length>>temp.cost;
		map[s].push_back(temp);
	}
	for(int i=0;i<=N;++i)
		for(int j=0;j<=K;++j)
			midL[i][j]=1<<30;
	DFS(1,0,0);
	if(minL!=(1<<30))
		cout<<minL<<endl;
	else
		cout<<-1<<endl;
system("pause");
return 0;
}