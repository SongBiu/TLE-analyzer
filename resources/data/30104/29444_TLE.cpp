// _Z1fi minl
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct road{
	int d;
	int l;
	int t;
	int next;
};
road r[10001];
int head[101];
int ri;
void roadin(int ss,int dd,int ll,int tt){
	r[ri].d=dd;
	r[ri].l=ll;
	r[ri].t=tt;
	r[ri].next=head[ss];
	head[ss]=ri;
	++ri;
}
int minl;
int n;
int vi[101];
int l_all;
int k;
void f(int s){
	if(s==n){
		minl=l_all;
		return;
	}
	for(int i=head[s];i!=0;i=r[i].next){
		l_all+=r[i].l;
		k-=r[i].t;
		if(!vi[r[i].d]&&k>=0&&l_all<minl){
			vi[r[i].d]=true;
			f(r[i].d);
			vi[r[i].d]=false;
		}
		l_all-=r[i].l;
		k+=r[i].t;
	}
}
int main(){
	while(1){
	int rr;
	cin>>k>>n>>rr;
	minl=10000000;
	memset(head,0,sizeof(head));
	memset(vi,0,sizeof(vi));
	l_all=0;
	vi[1]=true;
	ri=1;
	int ss,dd,ll,tt;
	for(int i=1;i<=rr;++i){
		scanf("%d%d %d %d",&ss,&dd,&ll,&tt);
		roadin(ss,dd,ll,tt);
	}

	f(1);
	if(minl!=10000000)
		printf("%d\n",minl);
	else 
		printf("-1\n");}
	return 0;
}