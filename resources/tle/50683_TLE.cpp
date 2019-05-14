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
    dfs(1);
    if(minLen>0)
        cout<<minLen<<endl;
    else
        cout<<"-1"<<endl;;


    return 0;
}