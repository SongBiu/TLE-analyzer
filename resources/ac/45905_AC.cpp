// _Z3Dfsi minLen
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int K,N,R;
struct Road{
	int d,L,t;
}; 

vector<vector<Road> >G(110);
int minLen = 1<<30;
int totalLen;
int totalCost;
int visited[110];
int minL[110][10100]; 
void Dfs(int s){
	if(s==N){
		minLen = min(totalLen,minLen);
		return;
	}
	int i; 
	for(i=0;i<G[s].size();i++)
		{
			int d = G[s][i].d;
			if(!visited[d])
			{
				int cost = totalCost+G[s][i].t;
				if(K<cost)
					continue;
				if(totalLen+G[s][i].L>minLen)
					continue;
				if(totalLen+G[s][i].L>=minL[d][cost])
					continue;
				totalLen+=G[s][i].L;
				totalCost+=G[s][i].t;
//				minL[d] = totalLen+G[s][i].L;
//				minC[d] = totalCost+G[s][i].t;
				minL[d][cost] = totalLen;
				visited[d] = 1;
				Dfs(d);
				totalLen -=G[s][i].L;
				totalCost -= G[s][i].t;
				visited[d] = 0;
				
			}
		}
}
int main(){
	cin>>K>>N>>R;
	int i,j,s;
	Road r;
	for(i=1;i<=R;i++){
		cin>>s>>r.d>>r.L>>r.t;
		if(s!=r.d)
			G[s].push_back(r);
	}
	memset(visited,0,sizeof(visited));
	for(i=0;i<110;i++)
		for(j=0;j<10100;j++)
		minL[i][j] = 10000;
	totalLen = 0;
	totalCost = 0;
	visited[1] = 1;
	Dfs(1);
	cout<<minLen;
	
}