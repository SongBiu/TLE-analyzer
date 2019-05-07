// _Z3dfsi
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 10000
#define MAXINT 100000000
struct edge
{
 int v;
 int len;
 int toll;
 int next;
}edges[2*MAX+1];
int edgenum;
int visit[101];
int head[101];
int mini_len;
int total_len,total_cost;
void add_edge(int a,int b,int len,int t)
{
 edges[edgenum].v = b;
 edges[edgenum].len = len;
 edges[edgenum].toll = t;
 edges[edgenum].next = head[a];
 head[a] = edgenum;
 edgenum++;
};
int n,k;
bool reach;
void dfs(int index)
{
 if(index == n)
 {
  reach = true;
  if(total_len < mini_len)
  mini_len = total_len;
  return;
 }
 int i;
 for(i = head[index]; i != -1; i= edges[i].next)
 {
  if(!visit[edges[i].v]
  && total_len + edges[i].len < mini_len
  && total_cost + edges[i].toll <=k)
  {
   visit[edges[i].v] = true;
   total_len += edges[i].len;
   total_cost += edges[i].toll;
   dfs(edges[i].v);
   visit[edges[i].v] = false;
   total_len -= edges[i].len;
   total_cost -= edges[i].toll;
  }
 }
}
int main()
{
 int r;
 scanf("%d%d%d",&k,&n,&r);
 int s,d,len,t;
 int i;
 for(i = 1;i <= n; i++)
 head[i] = -1;
 for(i = 1;i <= r; i++)
 {
  scanf("%d%d%d%d",&s,&d,&len,&t);
  add_edge(s,d,len,t);
 }
 memset(visit,false,sizeof(visit));
 total_len = 0;
 total_cost = 0;
 reach =false;
 mini_len = MAXINT;
 visit[1] = true;
 dfs(1);
 if(reach == false)
 printf("-1\n");
 else
 printf("%d\n",mini_len);
}