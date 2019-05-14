// _Z3dfsiii min_ans
#include<iostream>
#include<vector>
#include<string.h>
#define INF 0xffffff
using namespace std;
struct ROAD
{
	int d,l,t;
};
int K,N,R;
int min_len[105][10001];
vector<vector<ROAD> > road(105);
int min_ans=INF;
int vis[105];
void dfs(int i,int coin,int sum)
{
	if(min_len[i][coin]<=sum)
	return;
	else
	min_len[i][coin]=sum;
	if(sum>=min_ans)
	return;
	if(coin<0)
	return;
	if(i==N)
	{
		min_ans=sum;
		return;
	}
	for(int t=0;t<road[i].size();++t)
	{
		if(!vis[road[i][t].d])
		{
			vis[road[i][t].d]=1;
			dfs(road[i][t].d,coin-road[i][t].t,sum+road[i][t].l);
			vis[road[i][t].d]=0;
		}
		
	}
	vis[i]=0;
}


int main()
{
	memset(min_len,0x3f,sizeof(min_len));
	cin>>K>>N>>R;
	int s;
	ROAD tmp;
	for(int i=1;i<=R;++i)
	{
		cin>>s;
		cin>>tmp.d>>tmp.l>>tmp.t;
		road[s].push_back(tmp);
	}
	vis[1]=1;
	dfs(1,K,0);
	if(min_ans==INF)cout<<-1<<endl;
	else
	cout<<min_ans;
	return 0;
}