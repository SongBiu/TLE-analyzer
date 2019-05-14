// _Z3Dfsi minLen
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF = (1 << 30);
int K,N,R;
struct Road{
	int d,t,L;//d=>终点,t=>过路费,L=>路长度 
}; 
vector<vector<Road> > G(110);//100个城市
int totalLen;
int minLen;
int totalCost;
int visited[110];
int minL[110][10010];// mintime[i][j] :表示i=>城市i   j=>所花费的钱  最小的路程 

void Dfs(int s){
	
	if( s==N ){
		minLen = min(minLen,totalLen);
		return ;
	}
	
	for(int i=0; i<G[s].size(); ++i){	
		Road r = G[s][i];
		int Len = totalLen + r.L;
		int Cost = totalCost + r.t;
		if(Cost > K){
			continue;
		}	
		if(!visited[r.d]){
			if(Len>=minLen || Len >= minL[r.d][Cost])
				continue;
			minL[r.d][Cost] = Len;;
			totalLen += r.L;
			totalCost += r.t;
			visited[r.d] = 1;
			Dfs(r.d);
			visited[r.d] = 0;
			totalLen -= r.L;
			totalCost -= r.t;
		}
	} 
	
}

int main(){
	cin>>K>>N>>R;
	
	for(int i=0; i<R; i++){
		int s;
		Road r;
		cin>>s>>r.d>>r.L>>r.t;
		if(s != r.d){
			G[s].push_back(r);
		}
	
	}
	memset(visited,0,sizeof(visited));
	for(int i=0; i<110; i++)
		for(int j=0; j<10010; j++)
			minL[i][j] = INF;
	minLen = INF;
	totalLen = 0; 
	totalCost = 0;
	visited[1] = 1;
	Dfs(1);
	if( minLen<INF){
		cout<<minLen<<endl;
	}else
		cout<<-1<<endl;
	return 0;
} 