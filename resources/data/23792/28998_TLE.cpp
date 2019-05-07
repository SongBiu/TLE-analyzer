// _Z5checkiiiii
#include<iostream>
using namespace std;
int k,n,r,maxer=10000000;
int useds[110];//记录此城市有没有到过
bool t1=false;//记录是否有解
class ROAD{
public:
	int s[1000];
	int l[1000];
	int c[1000];
	int num;
}road[110];
void check(int x,int y,int coin,int length,int k_){
	if(coin>k) return;//剪枝
	if(length>=maxer) return;//剪枝
	if(y==1&&(coin+road[x].c[k_]<=k)){
		if( length+road[x].l[k_]<maxer) {maxer=length+road[x].l[k_];}
		t1=true;
		return;
	} 
	if(y==1) return;
	useds[x]=1;
	for ( int i=0;i<road[y].num;i++){
		if(useds[y]==1)  continue;//剪枝
		check(y,road[y].s[i],coin+road[x].c[k_],length+road[x].l[k_],i);//递归，s为这次的d
	}
	useds[x]=0;
	return;
}
int main(){
	cin>>k>>n>>r;
	int s,d,l,t;
	for ( int i=0;i<r;i++){
		cin>>s>>d>>l>>t;
		road[d].s[road[d].num]=s;
		road[d].l[road[d].num]=l;
		road[d].c[road[d].num]=t;
		road[d].num++;
	}
	if(road[n].num) 
		for( int i=0;i<road[n].num;i++)
			check(n,road[n].s[i],0,0,i);
	if(t1) cout<<maxer<<endl;
	else cout<<-1<<endl;
	
	return 0;
}