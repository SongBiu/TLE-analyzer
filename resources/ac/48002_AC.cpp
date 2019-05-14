// _Z3Dfsi minLen
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct Road{
    int d,L,t;
};
int K,N,R,S,D,L,T;
vector<vector<Road> > citymap(110);
int totalLen,totalCost;
int visited[110];
int minl[110][10100];
int minLen=1<<20;

void Dfs(int s){
    if(s==N){
        minLen=min(minLen,totalLen);
        return;
    }
    for(int i=0;i<citymap[s].size();i++){
        int d=citymap[s][i].d;
        if(!visited[d]){
            int cost=totalCost+citymap[s][i].t;
            int len=totalLen+citymap[s][i].L;
            if(cost>K)
                continue;
            if(len>=minLen)
                continue;
            if(len>=minl[d][cost])
                continue;

            totalCost=cost;
            totalLen=len;
            minl[d][cost]=len;
            visited[d]=1;
            Dfs(d);
            visited[d]=0;
            totalCost-=citymap[s][i].t;
            totalLen-=citymap[s][i].L;
        }
    }
}

int main(){
    cin>>K>>N>>R;
    for(int i=0;i<R;i++){
        Road r;
        cin>>S>>r.d>>r.L>>r.t;
        citymap[S].push_back(r);
    }
    for(int i=0;i<110;i++)
        for(int j=0;j<10100;j++)
            minl[i][j]=1<<20;
    memset(visited,0,sizeof(visited));
    totalLen=0;
    totalCost=0;
    visited[1]=1;
    Dfs(1);
    if(minLen<(1<<20))
        cout<<minLen<<endl;
    else
        cout<<"-1"<<endl;

    return 0;
}