// _Z4walki
#include <iostream>
#include <memory.h>
using namespace std;
int len[105];
int fee[105];
int used[105];
int LINK[105][105];
int dist[105][105];
int toll[105][105];
int K,N,R;
void walk(int t)
{
	int dest;
	for(int i=1; i<=LINK[t][0]; ++i)
	{
		dest=LINK[t][i];
		if( fee[t]+toll[t][dest]>K ) continue;
		if(dest==N)
		{
			if( len[N]<0 || len[t]+dist[t][N]<len[N] ) len[N]=len[t]+dist[t][N];
			continue;
		}
		if( fee[dest]>0 && fee[dest]<fee[t]+toll[t][dest] && len[dest]<len[t]+dist[t][dest] ) continue;
		if( used[dest]==0 )
		{
			fee[dest]=fee[t]+toll[t][dest];
			len[dest]=len[t]+dist[t][dest];
			used[dest]=1;
			walk(dest);
			used[dest]=0;
		}
	}
}
int main()
{
	memset(len,-1,sizeof(len));
	memset(fee,-1,sizeof(fee));
	cin>>K>>N>>R;
	int S,D,L,T;
	while(R--)
	{
		cin>>S>>D>>L>>T;
		++LINK[S][0];
		LINK[S][LINK[S][0]]=D;
		dist[S][D]=L;
		toll[S][D]=T;
	}
	len[1]=0;fee[1]=0;used[1]=1;
	walk(1);
	cout<<len[N]<<endl;
	return 0;
}