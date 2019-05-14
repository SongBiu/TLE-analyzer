// _Z3dfsi minLen
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int n,k,m;
struct road
{
    int d,l,t;
};
vector <vector<road> >g(110);

int minLen;
int totalLen;
int minCost;
int totalCost;
int minL[110][10010];
//minL[m][k]走到m城市花费k时的最小路径
int visited[110];
void dfs(int s)
{
    if(s==n)
        {minLen=min(minLen,totalLen);
        return ;}
    for(int i=0;i<g[s].size();i++)
    {
        road r=g[s][i];
        if(totalCost+r.t>k)
            continue;
        if(visited[r.d]==0)
            if(totalLen+r.l>=minLen)
            continue;
        if(totalLen+r.l>=minL[r.d][totalCost+r.t])//关键的剪枝
            continue;
        minL[r.d][totalCost+r.t]=totalLen+r.l;
        totalCost+=r.t;
        totalLen+=r.l;
        visited[i]=1;
        dfs(r.d);
        visited[i]=0;
        totalCost-=r.t;
        totalLen-=r.l;
    }

}
int main()
{
    cin>>k>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s;
        road r;
        cin>>s>>r.d>>r.l>>r.t;
        if(s!=r.d)
            g[s].push_back(r);
    }
    memset(visited,0,sizeof(visited));
    minLen=(1<<30);
    totalLen=0;
    totalCost=0;
    visited[1]=1;
    for(int i=0;i<110;i++)
        for(int j=0;j<10010;j++)
        minL[i][j]=1<<30;
    dfs(1);
    if(minLen!=(1<<30))
        cout<<minLen<<endl;
    else
        cout<<"-1"<<endl;;


    return 0;
}