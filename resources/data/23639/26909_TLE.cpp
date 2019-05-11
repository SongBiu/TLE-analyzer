// _Z8DFsearch sum
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int N,K,R;
int symbol[102];
int sum=99999999;
bool reached[101];
struct road
{
       int first;
       int second;
       int length;
       int cost;
}r[10000];
int cmp(const void *p1,const void *p2)
{
       road*r1=(road*)p1;
       road*r2=(road*)p2;
       if(r1->first!=r2->first) return r1->first-r2->first;
       return r1->second-r2->second;
}
void DFsearch(int num,int dis,int cost)
{
       if(dis>=sum) return;
       if(cost>K) return;
       if(num==N)
       {
              sum=dis;
              return;
       }
       if(symbol[num]==-1) return;
       int temp=1;
       while(1)
       {
              if(symbol[num+temp]!=-1) break;
              temp++;
       }
       for(int i=symbol[num];i<symbol[num+temp];i++)
       {
              if(reached[r[i].second]==1) continue;
              reached[r[i].second]=1;
              DFsearch(r[i].second,dis+r[i].length,cost+r[i].cost);
              reached[r[i].second]=0;
       }
}
int main()
{
    memset(symbol,-1,sizeof(symbol));
    scanf("%d%d%d",&K,&N,&R);
    for(int i=0;i<R;i++)
           scanf("%d%d%d%d",&r[i].first,&r[i].second,&r[i].length,&r[i].cost);
    qsort(r,R,sizeof(road),cmp);
    for(int i=0;i<R;i++)
           if(symbol[r[i].first]==-1)
           symbol[r[i].first]=i;
    symbol[1]=0;
    symbol[N]=R;
    reached[1]=1;
    DFsearch(1,0,0);
    if(sum==99999999) sum=-1;
    printf("%d\n",sum);
    return 0;
}
