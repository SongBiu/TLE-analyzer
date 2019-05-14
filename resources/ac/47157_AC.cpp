// _Z3dfsi minpath
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct eage{
	int d,l,t;
};
vector< vector<eage> > v(105);
int minL[105][10005];
int vis[105];
int K,R,N;
int minpath,totallen,totalcost;

void dfs(int x){
	if(x==N){
		minpath=min(minpath,totallen);
		return ;
	}
	for(int i=0; i<v[x].size();i++){
		eage e1=v[x][i];
		
		if(totalcost+e1.t>K){
			continue;
		}
		if(totallen+e1.l>=minpath)
		continue;
		if(vis[e1.d]==0){
			if(totallen+e1.l>=minL[e1.d][totalcost+e1.t])
			continue;
		minL[e1.d][totalcost+e1.t]=totallen+e1.l;
		totallen+=e1.l;
		totalcost+=e1.t;
		vis[e1.d]=1;
		dfs(e1.d);
		totallen-=e1.l;
		totalcost-=e1.t;
		vis[e1.d]=0;
		}	
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>K>>N>>R;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<105;i++){
		for(int j=0;j<10005;j++){
			minL[i][j]=1<<30;
		}
	}
	minpath=1<<30;
	totallen=0;
	totalcost=0;
	vis[1]=1;
	for(int i=1;i<=R;i++){
		int s;
		eage e;
		cin>>s>>e.d>>e.l>>e.t;
		v[s].push_back(e);
	}

	dfs(1);
	if(minpath<(1<<30))
	cout<<minpath<<endl;
	else
	cout<<-1<<endl;
	return 0;
}