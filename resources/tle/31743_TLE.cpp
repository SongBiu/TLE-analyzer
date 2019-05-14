// _Z4walkiii mi
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int k,n,r;
int len[110][110]={};
bool city[110];
int pri[110][110];
int mi=999999;

class edge
{
public:
	int end;
	int price;
	int length;
};

vector<edge> c[110];

void walk(int pos,int wayal,int kk)
{
		if(wayal>=mi)
		return;
	city[pos]=false;

	if(pos==n-1)
	{
		if(wayal<mi)
			mi=wayal;
		city[pos]=true;
		return ;
	}
	if(kk<0)
	{
		city[pos]=true;
		return ;
	}
	for(int i=0;i<c[pos].size();i++)
	{
		if(city[c[pos][i].end]&&kk>=c[pos][i].price)
		walk(c[pos][i].end,wayal+c[pos][i].length,kk-c[pos][i].price);
	}
	city[pos]=true;
	return ;
}
int main()
{
	
	memset(pri,-1,sizeof(pri));
	memset(city,true,sizeof(city));
	cin>>k>>n>>r;
	for(int i=0;i<r;i++)
	{
		int s,e,len,pri;
		cin>>s>>e>>len>>pri;
		edge temp;
		temp.end=e-1;
		temp.length=len;temp.price=pri;
		c[s-1].push_back(temp);

	}
	walk(0,0,k);
	if(mi==999999)
		cout<<-1<<endl;	

	else
		cout<<mi<<endl;


	return 0;
}