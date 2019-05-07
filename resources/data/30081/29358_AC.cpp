// _Z9find_roadi
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct road
{
	int length,toll;
};
int sum_roads[101][101]={0},K,N,R,Min=10000000;	
road map[101][101][100];
road spend[101]={0};
void find_road(int i);
int main()
{
	int i,j,p,x,y,l,t;
	memset(map,0,sizeof(map));
	memset(spend,0,sizeof(spend));
	cin>>K>>N>>R;
	for(p=0;p<R;++p)
	{
		cin>>y>>x>>l>>t;
		map[y][x][sum_roads[y][x]].length=l;
		map[y][x][sum_roads[y][x]].toll=t;
		++sum_roads[y][x];
	}
	find_road(1);
	if(Min<10000000)
		cout<<Min;
	else
		cout<<"-1";
	return 0;
}
void find_road(int i)
{
	int p,q;
	road t;
	if(i!=N)
	{
		for(p=N;p>0;--p)
		{
			if(sum_roads[i][p])
			{
				for(q=0;q<sum_roads[i][p];++q)
				{
					if(spend[p].length==0)
					{
						t=spend[p];
						spend[p].length=spend[i].length+map[i][p][q].length;
						spend[p].toll=spend[i].toll+map[i][p][q].toll;
						if(spend[p].toll<=K&&spend[p].length<Min)
							find_road(p);
						spend[p]=t;
					}
				}
			}
		}
	}
	else
	{
		if(spend[N].length<Min)
			Min=spend[N].length;
	}
}