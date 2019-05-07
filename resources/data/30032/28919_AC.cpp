// _Z3dfsiii
#include<iostream>   
#include<cstring>   
using namespace std;  
  
const int inf = 1000000000;  
const int Road = 10001;  
const int City = 101;  
  
struct {  
       int s,d,l,t;         //source,destination,length,toll   
       int next;            //指向相同source的下一条边          
} road[Road];  
  
int p;                      //指针    
int list_head[City];   
bool visit[City];  
int minlen;  
int K,N,R;  
  
void dfs(int s,int len,int toll){  
     if(len>minlen) return;  
     if(s==N){  
              if(len<minlen&&toll>=0) minlen = len;  
              return ;           
     }  
     for(int i= list_head[s];i!=-1;i=road[i].next){  
             int td = road[i].d;  
             int tl = road[i].l;  
             int tt = road[i].t;  
             if(!visit[td]&&tt<=toll){  
                         visit[td]=1;  
                         dfs(td,len+tl,toll-tt);                                 
                         visit[td]=0;  
             }          
     }  
}  
  
int main(){  
    int   i,j,s,d,l,t;  
    while(cin>>K>>N>>R){  
             memset(list_head,-1,sizeof(list_head));  
             memset(visit,0,sizeof(visit));  
             p = 0;  
             minlen=inf;  
             for(i=0;i<R;i++){  
                     cin>>s>>d>>l>>t;  
                     road[p].s=s;  
                     road[p].d=d;  
                     road[p].l=l;  
                     road[p].t=t;  
                     road[p].next=list_head[s];     //头一回见到这么建邻接链表的    
                     list_head[s]=p++;              //好吧我承认自己孤陋寡闻    
             }  
             visit[1]=1;  
             dfs(1,0,K);   
             if(minlen==inf) minlen = -1;  
             cout<<minlen<<endl;                            
    }  
    return 0;  
} 