// _Z3dfsi minlen
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int k,n,R;
struct road{
	int d,l,t;
};
vector< vector<road> > g(110);
int minlen;
int totallen;
int totalcost;
int visited[110];
void dfs(int s)
{
	if(s==n){
		minlen=min(minlen,totallen);
		return ;
	}
	for(int i=0;i<g[s].size();++i){
		road r=g[s][i];
		if(totalcost+r.t >k){
			continue;
		}
		if(!visited[r.d]){
			if(totallen+r.l>=minlen){
				continue;
			}
			totallen+=r.l;
			totalcost+=r.t;
			visited[r.d]=1;
			dfs(r.d);
			visited[r.d]=0;
			totallen-=r.l;
			totalcost-=r.t;
		}
	}
}
int main()
{
	cin>>k>>n>>R;
	for(int i=0;i<R;++i){
		int s;
		road r;
		cin>>s>>r.d>>r.l>>r.t;
		if(s!=r.d){
			g[s].push_back(r);
		}
	}
	memset(visited,0,sizeof(visited));
	totallen=0;
	minlen=1 <<30;
	totalcost=0;
	visited[1]=1;
	dfs(1);
	if(minlen<(1<<30)){
		cout<<minlen<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
	return 0;
}