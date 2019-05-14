// _Z3dfsiii mindis
//
//  main.cpp
//  POJ1724
//
//  Created by Mac on 2017/9/26.
//  Copyright © 2017年 Mac. All rights reserved.
//

#include <iostream>
#include<vector>
#define MAX 100000
using namespace std;
struct dico{
    int dis;
    int cos;
    dico(int dis,int cos):dis(dis),cos(cos){}
};
class road{
public:

    int end=0;
    int d=0;
    int c=0;
    road(int end,int d,int c):end(end),d(d),c(c){}
    road(){
        end=0;
        d=0;
        c=0;
    }
};

vector<vector<road>> R(110);

int vis[100];
vector<vector<int> >adj(100);
int k,n,r;
int mindis=MAX;
void dfs(int i,int d,int m){
    if(m<0||i>=n||d>=mindis||vis[i]==1) return;

    else if(i==n-1){
        if (d<mindis)
            mindis=d;
        return;
    }
    vis[i]=1;
    
    for(int s=0;s<R[i].size();++s){
        road r=R[i][s];
        if(vis[r.end]==0)
           dfs(r.end,d+r.d,m-r.c);}
    
    vis[i]=0;
}

int main(int argc, const char * argv[]) {
    cin>>k>>n>>r;
    R.resize(r);
    for(int i=0;i<r;++i){
        int beg,end,dis0,cos;
        cin>>beg>>end>>dis0>>cos;
        R[beg-1].push_back(road(end-1,dis0,cos));
    }
    dfs(0,0,k);
    if(mindis==MAX) cout<<-1<<endl;
    else cout<<mindis<<endl;
    return 0;
}
