// _Z3Dfsi minLen
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Road{
    int d,L,t;
};
int N,K,R;
int minLen,totalLen,totalCost;
vector<vector<Road> > G(120);
bool visited[120];
void Dfs(int s);
int main() {
    cin>>K>>N>>R;
    for(int i=0;i<R;i++){
        int s;cin>>s;
        Road r;cin>>r.d>>r.L>>r.t;
        if(s!=r.d){
            G[s].push_back(r);
        }
    }
    visited[1]=1;
    minLen=1<<30;
    Dfs(1);
    if(minLen<(1<<30))
    cout<<minLen;
    else cout<<"-1";
    return 0;
}
void Dfs(int s){
    if(s==N){
        minLen=min(minLen,totalLen);
        return ;
    }
    for(int i=0;i<G[s].size();i++){
        Road r=G[s][i];
        if(totalCost+r.t>K){
            continue;
        }
        if(!visited[r.d]){
            if(totalLen+r.L>=minLen)
                continue;
            totalLen+=r.L;
            totalCost+=r.t;
            visited[r.d]=1;
            Dfs(r.d);
            totalLen-=r.L;
            totalCost-=r.t;
            visited[r.d]=0;
        }
    }
}
