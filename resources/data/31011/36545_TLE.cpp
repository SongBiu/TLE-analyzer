// _Z5visitiii minl
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int money,sumcity,sumroad;
int minl;
struct road{
    int from,to;
    int money;
    int length;
    int next;
}way[10010];
struct city{
    int out;
    int cnt;
    int last;
}city[110];
//int dp[110][110];
int v[110] = {0};
void visit(int start,int cost,int l){
    if(l>minl)  return;
    if(cost>money)  return;
    if(l<minl&&start==sumcity){
        minl = l;
        return;
    }
    int t = city[start].cnt;
    if(t == 0)  return;
    for(int i = city[start].out;i!=0;i = way[i].next){
        int next = way[i].to;
        //cout << i << endl;
        if(v[next] == 0){
            int m = way[i].money;
            int le = way[i].length;
            if(cost + m <= money){
                v[next] = 1;
                visit(next,cost+m,l+le);
                v[next] = 0;
            }
        }
    }
}
int main(){
    memset(way,0,sizeof way);
    memset(city,0,sizeof city);
    memset(v,0,sizeof v);
    minl = 1e7;
    scanf("%d%d%d",&money,&sumcity,&sumroad);
    for(int i = 1;i<=sumroad;i++){
        scanf("%d %d %d %d",&way[i].from,&way[i].to,&way[i].length,&way[i].money);
        int cnt = city[way[i].from].cnt;
        if(cnt == 0){
            city[way[i].from].out = i;
            city[way[i].from].cnt = 1;
            city[way[i].from].last = i;
        }
        else{
            //cout << "= =";
            way[city[way[i].from].last].next = i;
            city[way[i].from].last = i;
        }
    }
    visit(1,0,0);
    if(minl == 1e7)  cout << "-1"<< endl;
    else cout << minl << endl;
}