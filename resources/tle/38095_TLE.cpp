// _Z1fii minl
#include<iostream>
#include<vector>
using namespace std;
int K,N,R,minl=1<<30;
class Road
{
	public:
		int d,l,t;
};
class City
{
	public:
		int money,length;
		City(int _money=0,int _length=0):money(_money),length(_length){}
};
vector<vector<City> > c(110);
vector<vector<Road> > v(110);
void f(int x,int y)
{
	if(x==N)
	{
		if(c[x][y].length<minl)
			minl=c[x][y].length;
		return;
	}
	vector<Road>::iterator p;
	for(p=v[x].begin();p!=v[x].end();p++)
	{
		if(c[x][y].money+p->t<=K)
		{
			vector<City>::iterator r;
			int flag=1;
			for(r=c[p->d].begin();r!=c[p->d].end();r++)
				if(r->money<=c[x][y].money+p->t&&r->length<=c[x][y].length+p->l)
				{
					flag=0;
					break;
				}
			if(!flag)
				continue;
			c[p->d].push_back(City(c[x][y].money+p->t,c[x][y].length+p->l));
			int l0=c[p->d].size();
			f(p->d,l0-1);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout); 	
	cin>>K>>N>>R;
	for(int i=1;i<=R;i++)
	{
		int s;
		Road r;
		cin>>s>>r.d>>r.l>>r.t;
		v[s].push_back(r);
	}
	c[1].push_back(City(0,0));
	f(1,0);
	cout<<minl;
}