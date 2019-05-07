#include <iostream>
#include <cstring>
using namespace std;
struct road{
    int S,D,L,T,next;
};
road r[10001];
int K,N,R;
int MinLen=1e7;
bool vist[101];
int head[101];
void gettocity(int m,int l,int c)
{
    if(l>MinLen)
        return;
    if(m==N && l<MinLen)
    {
        MinLen=l;
        return;
    }
    for(int i=head[m];i!=-1;i=r[i].next)
    {
        if(!vist[r[i].D] && c>=r[i].T)
        {
            vist[r[i].D]=true;
            gettocity(r[i].D,l+r[i].L,c-r[i].T);
            vist[r[i].D]=false;
        }
    }
    return;
}
int main(void)
{
cin>>K>>N>>R;
        memset(head,-1,sizeof(head));
        memset(vist,false,sizeof(vist));
        for(int i=0;i<R;i++)
        {
            int s,d,l,t;
            cin>>s>>d>>l>>t;
            r[i].S=s;
            r[i].D=d;
            r[i].L=l;
            r[i].T=t;
            r[i].next=head[s];
            head[s]=i;
        }
        gettocity(1,0,K);
        cout<<(MinLen<1e7?MinLen:-1)<<endl;
    return 0;
}

