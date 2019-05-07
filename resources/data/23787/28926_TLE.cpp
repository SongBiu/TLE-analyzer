#include<iostream>
using namespace std;
int money,n,r;
int ans=100000;
int ml[1000];
int mp[1000];
bool u[150]={};
class road{
public:
	int distination;
	int length;
	int paid;
	void make_road(int d_,int l_,int p_){
		distination=d_;
		length=l_;
		paid=p_;
	}
};
class city{
	public:
		road * proad;
		int roadnum;
		city(){
			roadnum=0;
			proad =new road[r+2];
		}
		void add_road(int d_,int l_,int p_){
			proad[roadnum].make_road(d_,l_,p_);
			roadnum++;
		}
};
city *pcity;
void findway(int s,int d,int p,int l){
	if(s==d){
		if(l<ans)
			ans=l;
		return;
	}
	if(p<=mp[s]&&l<=ml[s]){
		mp[s]=p;ml[s]=l;
	}
	for(int i=0;i<pcity[s].roadnum;i++){
		if(u[pcity[s].proad[i].distination])continue;
		int tp=p+pcity[s].proad[i].paid,tl=l+pcity[s].proad[i].length,ts=pcity[s].proad[i].distination;
		if(tp>money)
			continue;
		if(tl>=ans)
			continue;
		if(tp>=mp[ts]&&tl>=ml[ts])
			continue;
		u[ts]=1;
		findway(ts,d,tp,tl);
		u[ts]=0;
	}
	return;
}
int main(){
	cin>>money>>n>>r;
	pcity=new city[n+2];
	for(int i=0;i<r;i++){
		int s,d,l,p;
		cin>>s>>d>>l>>p;
		pcity[s].add_road(d,l,p);
	}
	for(int i=0;i<=n;i++){
		ml[i]=100000;
		mp[i]=100000;
	}
	u[1]=1;
	findway(1,n,0,0);
	if(ans==100000)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}