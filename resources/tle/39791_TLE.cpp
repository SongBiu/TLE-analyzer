// _Zdfsiii min_path
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

typedef struct point{
    int D, L, T;
}point;

vector< vector<point> > point_sets(110);

int mem_spend[110][10002];
int visited[110];
int min_path = 1 << 30;
int total_spend = 0;
int total_len = 0;

void dfs(int s, int e, int k){
    if(s == e){
        min_path = min(min_path, total_len);
        return ;
    }
    for(int i = 0; i < point_sets[s].size(); ++i){
        point tmp = point_sets[s][i];
        if(!visited[tmp.D]){

            int tmp_cost = total_spend + tmp.T;
            if(tmp_cost > k)
                continue;
            /* printf("tmp_cost %d dest %d\n", total_spend, tmp.D); */
            int tmp_len = total_len + tmp.L;
            if(tmp_len > min_path)
                continue;
            /* if(mem_spend[tmp.D][tmp_cost] && mem_spend[tmp.D][tmp_cost] < tmp_len) */
            /*     continue; */
            total_len = tmp_len;
            total_spend = tmp_cost;
            mem_spend[tmp.D][tmp_cost] = tmp_len;
            visited[tmp.D] = 1;
            dfs(tmp.D, e, k);
            visited[tmp.D] = 0;
            total_len -= tmp.L;
            total_spend -= tmp.T;
        }
    }
}

int main(){
    int K, N, R;
    cin>>K>>N>>R;

    for(int i = 0; i < R; ++i){
        int s;
        point p;
        cin>>s>>p.D>>p.L>>p.T;
        point_sets[s].push_back(p);
    }
    visited[1] = 1;
    memset(visited, 0, sizeof(visited));
    dfs(1, N, K);
    printf("%d\n", min_path);
    return 0;
}
