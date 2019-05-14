// _Z5Roadsiii mindist
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int K,N,mindist=1<<30;
int visited[101];
struct road
{
    int s,d,l,t;
};
vector<road> graph[101];
int cache[101][10001];

void Roads(int pos,int cost,int dist)
{
    if(pos==N) {mindist=min(mindist,dist);return;}
    if(cache[pos][cost]!=-1&&cache[pos][cost]<=dist) return;
    cache[pos][cost]=dist;
    if(dist>=mindist) return;
    visited[pos]=1;
    vector<road>::iterator p;
    for(p=graph[pos].begin();p!=graph[pos].end();p++)
    {
        if(visited[(*p).d]==1) continue;
        if(cost+(*p).t>K) continue;
        Roads((*p).d,cost+(*p).t,dist+(*p).l);
    }
    visited[pos]=0;
    return;
}

int main()
{
    int R,i;
    scanf("%d%d%d",&K,&N,&R);
    memset(visited,0,sizeof(visited));
    memset(cache,-1,sizeof(cache));
    for(i=0;i<R;i++)
    {
        road input;
        scanf("%d%d%d%d",&input.s,&input.d,&input.l,&input.t);
        graph[input.s].push_back(input);
    }
    Roads(1,0,0);
    if(mindist!=1<<30) cout<<mindist<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
