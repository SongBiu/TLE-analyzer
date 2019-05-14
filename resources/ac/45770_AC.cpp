// _Z3dfsi minLen
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int K,N,R;
struct Road{
	int d,L,t;
};
vector<vector<Road> > G(110);
int minLen;
int totalLen;
int totalCost;
int visited[110];
int midL[110][10010];//midL[i][j]表示到第i个城市花了j元钱 
void dfs(int s)
{
	if(s==N){
		minLen=min(minLen,totalLen);
		return ;
	}
	for(int i=0;i<G[s].size();i++){
		Road r=G[s][i];
		if(totalCost+r.t>K)
		  continue;
		if(!visited[r.d]){
			if(minLen<=totalLen+r.L)
			  continue;
			if(totalLen+r.L>=midL[r.d][totalCost+r.t])
		      continue;
		    midL[r.d][totalCost+r.t]=totalLen+r.L;
			totalCost+=r.t;
			totalLen+=r.L;
			visited[r.d]=1;
			dfs(r.d);
			totalCost-=r.t;
		    totalLen-=r.L;
		    visited[r.d]=0;
	    }
	}
}
int main()
{
	cin>>K>>N>>R;
	for(int i=0;i<R;i++){
		int s;
		Road r;
		cin>>s>>r.d>>r.L>>r.t;
		if(s!=r.d)
		  G[s].push_back(r);
	}
	for(int i=0;i<110;i++)
	  for(int j=0;j<10010;j++)
	    midL[i][j]=1<<30;
	minLen=1<<30;
	totalLen=0;
	totalCost=0;
	memset(visited,0,sizeof(visited));
	visited[1]=1;
	dfs(1);
	if(minLen<(1<<30))
	  cout<<minLen<<endl;
	else
	  cout<<"-1"<<endl;
	return 0;
}
