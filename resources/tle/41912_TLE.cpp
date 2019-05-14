// _Z3dfsi minlen
#include <iostream>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std;
int minlen,totallen,totalcost,k,r,n;
int visited[110];
struct road
{
    int d,t,l;
};
vector<vector<road> >g(110);
void dfs(int s)
{
    if(s==n)
    {
        minlen=min(minlen,totallen);     //全部走完
        return;
    }
    for(int i=0;i<g[s].size();i++)
    {
        road r=g[s][i];
        if(totalcost+r.t>k)continue; //不走下面的 continue的用法是跳过本次循环下面未执行的语句
        if(!visited[r.d])      //???r.d是几呢
        {
            visited[r.d]=1;
            totallen+=r.l;
            totalcost+=r.t;
            dfs(r.d);
            visited[r.d]=0;
            totallen-=r.l;
            totalcost-=r.t;
        }
    }

}
int main()
{

    while(cin>>k>>n>>r)
    {
        for(int i=0;i<r;i++)    //共r条路
        {
            int s;
            road r;
            scanf("%d%d%d%d",&s,&r.d,&r.l,&r.t);
            if(s!=r.d)g[s].push_back(r);   //s代表起点 二维数组 起点 终点不能相同
        }
        memset(visited,0,sizeof(visited));
        totallen=0;
        minlen=1<<30;
        totalcost=0;
        visited[1]=1;
        dfs(1);
        if(minlen<(1<<30))cout<<minlen<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}