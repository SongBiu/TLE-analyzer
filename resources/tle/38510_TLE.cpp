// _Z3Dfsii L
#include<iostream>
#include<vector>
using namespace std;
int N,M,R,L=(1<<30),tmpL=0;
bool haveVi[110]={};
struct Road{
       int e,l,t;
};
vector<vector<Road> > Map(110);//这么写的意思是，提前划出110个以vector<Road>为元素的vector变量Map 
void Dfs(int seq,int rem){//用rem块钱，从seq出发，寻找到达N-1的路 
     if( seq == N){
         L = min(L,tmpL);
         return ;
     }
     for( int i=0;i<Map[seq].size();++i){
          if( Map[seq][i].t <= rem && !haveVi[Map[seq][i].e]){
              haveVi[Map[seq][i].e] = true;
              tmpL += Map[seq][i].l;
              Dfs(Map[seq][i].e,rem-Map[seq][i].t);
              tmpL -= Map[seq][i].l;
              haveVi[Map[seq][i].e] = false;
          }
     }
}
int main(){
    cin>>M>>N>>R;//M=money
    for( int i=1;i<=R;++i){
         int s,e,l,t;
         cin>>s>>e>>l>>t;
         if( s != e){
             Road r;
             r.e = e;
             r.l = l;
             r.t = t;
             Map[s].push_back(r);
         }
    }
    Dfs(1,M);
    if( L == (1<<30)) L = -1;
    cout<<L<<endl;
    return 0;
}
