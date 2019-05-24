// _Z3dfsi minLen
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#include <vector>

int N,K,R;
struct Road
{
	int e,l,t;	// e终点, l长度,t花费
};
vector< vector<Road> > G(110);
int visited[110];
int minLen=1<<30;
int len=0;
int cost=0;
int mid[110][10010]; //空间换时间: mid[k][cost] 走到k节点,已经花费了cost的最短路径长度

void dfs(int i)	//dfs+剪枝
{
	if(i==N)
	{
		if(len<minLen)
			minLen=len;
		return;
	}
	int j;
	for(j=0;j<G[i].size();j++)
	{
		Road r=G[i][j];
		if(visited[r.e]!=0)	//剪枝
			continue;
		if(cost+r.t<=K)
		{
			if(len+r.l>=minLen) //剪枝
				continue;
			if(len+r.l>=mid[r.e][cost+r.t])	//剪枝
				continue;
			mid[r.e][cost+r.t]=len+r.l;

			visited[r.e]=1;
			len+=r.l;
			cost+=r.t;
			dfs(r.e);
			visited[r.e]=0;
			len-=r.l;
			cost-=r.t;
		}
	}
}

int main()
{
	cin>>K>>N>>R;
	int i,j;
	for(i=1;i<=R;i++)
	{
		int s;
		Road r;
		cin>>s>>r.e>>r.l>>r.t;
		if(s!=r.e)
			G[s].push_back(r);
	}
	for(i=0;i<110;i++)
		for(j=0;j<10010;j++)
			mid[i][j]=1<<30;
	memset(visited,0,sizeof(visited));
	visited[1]=1;
	dfs(1);

	if(minLen==1<<30)
		cout<<"-1"<<endl;
	else
		cout<<minLen<<endl;

/*	//show test...
 	int j;
	for(i=1;i<=N;i++){
		Road r;
		for(j=0;j<G[i].size();j++)
		{
			r=G[i][j];
			cout<<i<<"->"<<r.e<<":"<<r.l<<"="<<r.t<<"  ";
		}
		cout<<endl;
	}
*/
   return 0;
}