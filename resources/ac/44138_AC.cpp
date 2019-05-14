// _Z3dfsi minLen
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct road
{
    int d,l,t;
};
int K,N,R;
vector< vector<road> >G(110);
int minl[110][10010];
int vis[10010];
int minLen,totalCost,totalLen;

void dfs(int s)
{
    if(s==N)
    {
        minLen=min(minLen,totalLen);
        return ;
    }
    for(int i=0;i<G[s].size();i++)
    {
        road r=G[s][i];
        if(totalCost+r.t>K)
        {
            continue;
        }
        if(!vis[r.d])
        {
            if(totalLen+r.l>minLen)
            {
                continue;
            }
            if(totalLen+r.l>=minl[r.d][totalCost+r.t])
            {
                continue;
            }
            minl[r.d][totalCost+r.t] = totalLen+r.l;
            totalLen+=r.l;
            totalCost+=r.t;
            vis[r.d]=1;
            dfs(r.d);
            vis[r.d]=0;
            totalLen-=r.l;
            totalCost-=r.t;
        }
    }
}
int main()
{
    cin>>K>>N>>R;
    for(int i=0;i<R;i++)
    {
        int s;
        road r;
        cin>>s>>r.d>>r.l>>r.t;
        if(r.d!=s)
        {
            G[s].push_back(r);
        }
    }
    for(int i=0;i<110;i++)
    {
        for(int j=0;j<10010;j++)
        {
            minl[i][j]=0x3f3f3f3f;
        }
    }
    minLen=0x3f3f3f3f;totalCost=0;totalLen=0;
    vis[1]=1;
    dfs(1);
    if(minLen==0x3f3f3f3f)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<minLen<<endl;
    }
    return 0;
}
