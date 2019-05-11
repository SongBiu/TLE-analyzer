// _Z3dfsiii min_l
#include<iostream>

using namespace std;

int min_length[102]={};
int min_coin[102]={};
int road_length[102][102][1000]={};
int road_coin[102][102][1000]={};
int road_num[102][102]={};
int K=0,N=0,R=0;
int min_l=999999;
int S=0,D=0,L=0,T=0;
int visited[100]={};
void dfs(int length,int coin,int city);
int main()
{
	cin>>K;
	cin>>N;
	cin>>R;

	for(int i=1;i<=R;i++)
	{
		cin>>S>>D>>L>>T;
		road_length[S][D][  road_num[S][D]  ]=L;
		road_coin[S][D][  road_num[S][D]  ]=T;
		road_num[S][D]++;
	}

	dfs(0,0,1);
	cout<<min_l<<endl;


	return 0;
}

void dfs(int length,int coin,int city)
{	
	if(city==N)
	{
		if(length<min_l)
			min_l=length;
	}

	for(int i=2;i<=N;i++)
	{
		if(i==city)
			continue;

		for(int j=0;j<road_num[city][i];j++)
		{
			if(coin+road_coin[city][i][j]<=K && visited[i]==0)
			{
				visited[i]=1;
				dfs(length+road_length[city][i][j],coin+road_coin[city][i][j],i);
				visited[i]=0;
			}
		}
	}

	return;
}

