// _Z2dsi mlen
//http://bailian.openjudge.cn/practice/1724

#include <iostream>
#include <vector>
using namespace std;

class road
{
public:
    int d,l,t;
    void print()
    {
        cout<<d<<"\t"<<l<<"\t"<<t<<endl;
    }
};

vector<vector<road> >map(110);
int mark[110]{0};
int tcost=0;
int tlen=0;
int mlen=1<<30;
int k,n,r;
int minL[110][10100]; //minL[i][j]表示从1到i点的，花销为j的最短路的长度

void ds(int s);
int main(int argc, const char * argv[]) {
    
    cin>>k>>n>>r;
    for(int i=0;i<r;i++)
    {
        int s;
        road r;
        cin>>s>>r.d>>r.l>>r.t;
        if(s!=r.d)
        {
            map[s].push_back(r);
        }
    }
    for( int i = 0;i < 110; ++i )
        for( int j = 0; j < 10100; ++ j )
            minL[i][j] = 1 << 30;
    /*
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<map[i].size();j++)
        {
            map[i][j].print();
        }
    }
     */
    
    ds(1);
    mark[1]=1;
    if( mlen<(1<<30) )
    {
        cout<<mlen<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}

void ds(int s)
{
    //mark[s]=1;//不能这样做
    if(s==n)
    {
        mlen=min(tlen,mlen);
        //cout<<"tlen:"<<tlen<<endl;
        return;
    }
    else
    {
        for(int i=0;i<map[s].size();i++)
        {
            if(mark[map[s][i].d]!=1)
            {
                if(tcost+map[s][i].t>k||tlen+map[s][i].l>mlen/*||tlen+map[s][i].l>minL[map[s][i].d][tcost+map[s][i].t]*/)
                {
                    continue;
                }
                tlen+=map[s][i].l;
                tcost+=map[s][i].t;
                //minL[map[s][i].d][tcost]=tlen;
                //mark[map[s][i].d]=1;
                mark[map[s][i].d]=1;
                ds(map[s][i].d);
                mark[map[s][i].d]=0;
                tlen-=map[s][i].l;
                tcost-=map[s][i].t;
            }
        }
    }
    //mark[s]=0;
}

/*
 5
 6
 7
 1 2 2 3
 2 4 3 3
 3 4 2 4
 1 3 4 1
 4 6 2 1
 3 5 2 0
 5 4 3 2
 
 answer:
 11
 */
