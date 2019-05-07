#include<iostream>
#include <cstring>
using namespace std;
const int inf=1e7;
const int CitySize=101;
const int RoadSize=10001;
struct
{
    int S,D,L,T; 
    int next;     
}road[RoadSize];

int pr;   
int K,N,R;  
int MinLen;
bool vist[CitySize];
int ListTable_Head[CitySize];
void DFS(int NowCity,int NowLen,int RestMoney)
{
    if(NowLen>MinLen)
        return;

    if(NowCity==N && RestMoney>=0 && NowLen<MinLen)
    {
        MinLen=NowLen;
        return;
    }

    for(int i=ListTable_Head[NowCity];i!=-1;i=road[i].next)
    {
        int tD=road[i].D;
        int tL=road[i].L;
        int tT=road[i].T;

        if(!vist[tD] && RestMoney>=tT)
        {
            vist[tD]=true;
            DFS(tD,NowLen+tL,RestMoney-tT);
            vist[tD]=false;
        }
    }
    return;
}

int main(void)
{
    while(cin>>K>>N>>R)
    {
        memset(ListTable_Head,-1,sizeof(ListTable_Head));
        memset(vist,false,sizeof(vist));
        pr=0;
        MinLen=inf;

        for(int i=1;i<=R;i++)
        {
            int s,d,l,t;
            cin>>s>>d>>l>>t;
            road[pr].S=s;
            road[pr].D=d;
            road[pr].L=l;
            road[pr].T=t;
            road[pr].next=ListTable_Head[s];
            ListTable_Head[s]=pr++;
        }

        DFS(1,0,K);

        cout<<(MinLen<inf?MinLen:-1)<<endl;
    }
    return 0;
}
