// _Z3dfsi minLen
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Road{
    int e,L,T;
}roads[10100];
int N,K,R;
int minLen,totalLen,totalCost;
int vis[110];
int midL[110][10100];
vector<vector<Road> > cityMap(110);
void dfs(int s){
    if(s==N){
        minLen=min(minLen,totalLen);
        return;
    }
    if(totalLen>=minLen) return;
    for(int i=0;i<cityMap[s].size();i++){
        int e=cityMap[s][i].e;
        int cost=totalCost+cityMap[s][i].T;
        if(vis[e]) continue;
        if(cost>K) continue;
        if(totalLen+cityMap[s][i].L>=midL[e][cost]) continue;
        vis[e]=1;
        totalLen+=cityMap[s][i].L;
        totalCost+=cityMap[s][i].T;
        midL[e][cost]=totalLen;
        dfs(e);
        vis[e]=0;
        totalLen-=cityMap[s][i].L;
        totalCost-=cityMap[s][i].T;
    }
}
int main(){
    cin>>K>>N>>R;
    for(int i=0;i<R;i++){
        Road r;
        int s;
        cin>>s>>r.e>>r.L>>r.T;
        cityMap[s].push_back(r);
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<110;i++){
        for(int j=0;j<10100;j++){
            midL[i][j]=1<<30;
        }
    }
    totalCost=0;
    totalLen=0;
    minLen=1<<30;
    vis[1]=1;
    dfs(1);
    cout<<minLen<<endl;
    return 0;
}
