#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>
#define PI acos(-1.0)
#define Max 10005
#define inf 1<<28
using namespace std;

int n;

struct kdq
{
    int v,l,c,n;
    friend bool operator<(const kdq&a,const kdq&b)//根据长度从小到大排序。要是长度相等，则根据花费的钱从小到大排序
    {
        if(a.l!=b.l)
            return a.l>b.l;
        else
            return a.c>b.c;
    }
};

int u[Max],v[Max],l[Max],c[Max];
int head[Max],next[Max];//邻接表
int money;


int BFS()
{
    priority_queue<kdq>q;//优先队列
    kdq xx;
    xx.v=1;
    xx.c=0;
    xx.l=0;
    q.push(xx);//从1出发。
    while(!q.empty())
    {
        kdq temp=q.top();
        q.pop();
        if(temp.v==n)//找到n则跳出
            return temp.l;
        for(int i=head[temp.v]; i>=0; i=next[i])//由该点出发遍历一遍
        {
            if(temp.c+c[i]<=money)//如果pre的花费加上本次的花费小于money，则将这点入队。
            {
                kdq qq;
                qq.c=temp.c+c[i];//到达此次的总花费
                qq.l=temp.l+l[i];//到达此点的总路径
                qq.v=v[i];
                q.push(qq);//入队
            }
        }
    }
    return -1;
}

int main()
{
    int i,j,m;
    while(scanf("%d%d%d",&money,&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&u[i],&v[i],&l[i],&c[i]);
            next[i]=head[u[i]];
            head[u[i]]=i;
        }
        cout<<BFS()<<endl;
    }
    return 0;
}
