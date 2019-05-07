// _Z3DFSii
#include<iostream>
#include<map>
#include<stdio.h>
#define MAXL 999999999
#define MAXT 999999999
using namespace std;

struct Info{
    int d;
    int l;
    int t;
    Info(int d,int l,int t){
        this->d=d;
        this->l=l;
        this->t=t;
    }
};
multimap<int,Info> roads=multimap<int,Info>();
int visited[110];
int res=MAXL;
int far=0;
int K,N,R;

void DFS(int pos,int fee){
    if(pos==N){
        if(far<res){
            res=far;
        }
        return;
    }
    if(far>=res) return;

    visited[pos]=1;
    map<int,Info>::iterator iter;
    iter=roads.find(pos);
    if(iter!=roads.end()){
        for(;iter!=roads.upper_bound(pos);iter++){
            int d=iter->second.d;
            int t=iter->second.t;
            int l=iter->second.l;
            if(visited[d]==false && t<=fee){
                far+=l;
                DFS(d,fee-t);
                far-=l;
            }
        }
    }
    visited[pos]=0;
    return;
}

int main(){
    for(int i=0;i<110;i++){
        visited[i]=0;
    }
    cin>>K>>N>>R;
    for(int i=0;i<R;i++){
        int s,e,l,t;
        scanf("%d %d %d %d",&s,&e,&l,&t);
        roads.insert(pair<int,Info>(s,Info(e,l,t)));
    }
    DFS(1,K);
    if(res==MAXL){
        printf("-1");
    }
    else{
        printf("%d",res);
    }
    return 0;
}
