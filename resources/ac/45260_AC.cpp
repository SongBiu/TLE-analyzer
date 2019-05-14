// _Z3DFSi minlen
//题目编号:POJ1724
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int K,N,R;  //存放钱数，城市数，道路数

struct Road  //存放路的信息
{
    int d;   //路终点
    int L;   //路长度
    int t;   //路费
};

vector< vector< Road> > G(110);
int minlen;  //目前找到的最段路径
int minl[110][10010]; //到y城市用了x钱的最短路径
int totallen;  //目前遍历的这条路目前的长度
int totalcost;  //目前遍历的这条路目前的花费
int visited[110];   //城市是否走过

void DFS(int s)
{
    if( s == N){   //如果已经到终点了
        minlen = min(minlen, totallen) ;
        return ;
    }

    for(int i = 0; i < G[s].size() ; i++){  //从城市s的每一条边出发进行DFS
        Road r = G[s][i] ;
        if(totalcost + r.t > K)  //如果当前边钱数不够，就看s的另一条边
            continue;

        if(totallen + r.L >= minl[r.d][totalcost + r.t] )   //如果此前的路径到过该点并且花了同样(甚至更少)的钱而总长度更小，那么这条路就不用继续找下去了
            continue;

        //如果此前的路径到该点花了同样的钱路径长度却比当前路径长，那么更新minl
        minl[r.d][totalcost + r.t] = totallen + r.L;

        if(! visited[r.d] ){  //如果这条路的终点城市没有走过，那么走它
            if(minlen <= totallen + r.L)
                continue;
            totallen += r.L;
            totalcost += r.t;
            visited[r.d] = 1;
            DFS(r.d) ;  //然后又从这条路的终点城市开始遍历
            //但是呢，遍历完r.d后再遍历s其他的路的时候，要把现在走的r.d还原成没有走过的状态
            visited[r.d] = 0;
            totalcost -= r.t;
            totallen -= r.L;
        }
    }
}


int main()
{
    cin >> K >> N >> R;   //输入原始数据
    for(int i = 0; i < R; i++){
        int s;   //边起点
        Road r;   //边信息
        cin >> s >> r.d >> r.L >> r.t ;
        if(s != r.d){  //如果起点不等于终点，才把这条路加入链接表
            G[s].push_back(r) ;
        }
    }
    //初始化
    memset(visited, 0 , sizeof(visited) );
    totallen = 0;
    minlen = 1 << 30;
    totalcost = 0; 
    //开始寻路
    visited[1] = 1;
    for(int i = 0; i < 110; i++){
        for(int j = 0; j < 10010; j++){
            minl[i][j] = 1 << 30;
        }
    }
    DFS(1);
    if(minlen < (1 << 30) ){
        cout << minlen << endl;
    }

    else
        cout << -1;
    return 0;
}