// _Z3dfsi minLen
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int K,N,R;
const int maxn=110;
bool visited[maxn];
struct Road
{
    int d,L,t;
};
int minL[110][10010];
vector < vector <Road> > cityMap(110);
const int INF=1<<30;
int totalLen;
int totalCost;
int minLen;


void dfs(int s)
{
    if(s==N)
    {
        minLen= min(minLen,totalLen);
        return ;
    }
    for(int v=0;v<cityMap[s].size();v++)
    {
        Road r=cityMap[s][v];
        if(totalCost + r.t >K)
        {
            continue;
        }
        if(!visited[r.d])
        {
            if(totalLen+r.L>= minLen)
                continue;
            if(totalLen+r.L >= minL[r.d][totalCost+r.t])
                continue;
            minL[r.d][totalCost+r.t]=totalLen+r.L;
            totalLen+=r.L;
            totalCost += r.t;
            visited[r.d]=true;
            dfs(r.d);
            visited[r.d]=false;
            totalLen -=r.L;
            totalCost-=r.t;
        }
    }

}
int main()
{
    fill(minL[0],minL[0]+110*10010,INF);
    memset(visited,0,sizeof(visited));
    cin>>K>>N>>R;
    for(int i=0;i<R;i++)
    {
        int s;
        Road r;
        cin >> s >> r.d >> r.L >> r.t;
        if(s!= r.d)
        {
            cityMap[s].push_back(r);
        }
    }
    totalLen=0;
    totalCost=0;
    minLen=INF;
    visited[1]=true;
    dfs(1);
    if(minLen==INF)
    {
        cout << "-1"<< endl;
    }
    else
    {
        cout << minLen << endl;
    }
    return 0;
}
