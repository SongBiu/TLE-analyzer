// _Z5searchiii
#include<iostream>
using namespace std;
int K,N,R;
int minlen=1<<30;
int mid[101][10001];
struct data
{
	int s;
	int d;
	int len;
	int money;
};
data way[10001];
int mark[10001];
void search(int x,int left,int len)
{
	if(left<0||len>minlen)
		return;

	if(x==N)
	{
		if(len<minlen)
			minlen=len;
		return;
	}

	if(mid[x][left]>len)
	{
		mid[x][left]=len;
	}
	else
		return;

	for(int i=1;i<=R;i++)
	{
		if((way[i].s==x)&&(mark[i]==0))
		{
			mark[i]=1;
			search(way[i].d,left-way[i].money,len+way[i].len);
			mark[i]=0;
		}	
	}

}
int main()
{
	cin>>K>>N>>R;
	
	for(int i=1;i<=R;i++)
	{
		cin>>way[i].s>>way[i].d>>way[i].len>>way[i].money;
		mark[i]=0;
	}

	for(int i=1;i<=N;i++)
		for(int j=0;j<=K;j++)
			mid[i][j]=1<<30;


	search(1,K,0);

	if(minlen!=1000000)
	cout<<minlen<<endl;
	else
		cout<<-1<<endl;

	return 0;
}