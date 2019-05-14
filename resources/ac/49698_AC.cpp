// _Z3dfsiii minLen
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=1e9;
int K,n,m,vis[110]={},minLen=INF,minL[110][10010];
struct Node{
	int d;
	int len;
	int cost;
	Node(int _d,int _len,int _cost){
		d=_d;
		len=_len;
		cost=_cost;
	}
};
vector<Node> Adj[110];
void dfs(int now,int nowLen,int nowCost){
	if(nowLen>minLen){
		return;
	}
	if(nowCost>K){
		return;
	}
	if(nowLen>=minL[now][nowCost]){
		return;
	}else{
		minL[now][nowCost]=nowLen;
	}
	if(now==n){
		minLen=min(minLen,nowLen);
		return;
	}
	for(int i=0;i<Adj[now].size();i++){
		Node t=Adj[now][i];
		if(!vis[t.d]){
			vis[t.d]=1;
			dfs(t.d,nowLen+t.len,nowCost+t.cost);
			vis[t.d]=0;
		}
	}
}
int main(){
	scanf("%d%d%d",&K,&n,&m);
	fill(&minL[0][0],&minL[0][0]+110*10010,INF);
	int tS,tD,tLen,tCost;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&tS,&tD,&tLen,&tCost);
		if(tS!=tD){
			Adj[tS].push_back(Node(tD,tLen,tCost));
		}
	}
	vis[1]=1;
	dfs(1,0,0);
	vis[1]=0;
	if(minLen<INF){
		printf("%d\n",minLen);
	}else{
		printf("-1\n");
	}
	return 0;
}