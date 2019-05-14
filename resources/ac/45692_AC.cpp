// _Z3dfsi minlen
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct road
{
    int d,l,t;
};
vector< vector<road> > G(110);
int minlen=0;
int totallen=0;
int totalcost=0;
int minl[110][10010];
int N,K;
int visited[110];
void dfs(int s)
{
    int i,j;
    if(s==N)
    {
        minlen=min(minlen,totallen);
        return;
    }
    for(i=0;i<G[s].size();i++)
    {
        road r=G[s][i];
        if(totalcost+r.t>K)
            continue;
        if(!visited[r.d])
        {
            if((totallen+r.l)>=minlen)
                continue;
            if((totallen+r.l)>=minl[r.d][totalcost+r.t])
                continue;
            minl[r.d][totalcost+r.t]=totallen+r.l;
            totalcost+=r.t;
            totallen+=r.l;
            visited[r.d]=1;
            dfs(r.d);
            totalcost-=r.t;
            totallen-=r.l;
            visited[r.d]=0;
        }
    }
}
int main()
{
    int i,j,r,s;
    cin>>K>>N>>r;
    for(i=0;i<r;i++)
    {
        road x;
        cin>>s>>x.d>>x.l>>x.t;
        if(s!=x.d)
        {
            G[s].push_back(x);
        }
    }
    for(i=0;i<110;i++)
        for(j=0;j<10010;j++)
            minl[i][j]=1<<30;
    minlen=1<<30;
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    dfs(1);
    if(minlen<(1<<30))
    {
        cout<<minlen<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
