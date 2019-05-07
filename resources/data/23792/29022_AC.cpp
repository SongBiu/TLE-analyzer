#include<iostream>
using namespace std;
struct{
int s,d,l,t;
int next;
}road[10010];
int k,n,r,miner;
int vist[110],headlist[110];
void check(int v,int mon,int len){
	if(len>miner) return;
	if(len<miner&&v==n) {miner=len;return;}
	for ( int i=headlist[v];i!=-1;i=road[i].next)
		if((!vist[road[i].d])&&mon>=road[i].t){
			vist[road[i].d]=1;
			check(road[i].d,mon-road[i].t,len+road[i].l);
			vist[road[i].d]=0;
		}
}
int main(){
cin>>k>>n>>r;
for ( int i=0;i<110;i++)
	headlist[i]=-1;
for ( int i=0;i<r;i++){
	cin>>road[i].s>>road[i].d>>road[i].l>>road[i].t;
	road[i].next=headlist[road[i].s];
	headlist[road[i].s]=i;
}
miner=9999999999;
check(1,k,0);
if(miner==9999999999) cout<<-1<<endl;
else cout<<miner<<endl;
return 0;
}