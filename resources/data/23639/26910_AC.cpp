// _Z3DFSiii
#include<iostream>
#include<string.h>
using namespace std;

#define MaxCity 101
#define MaxRoad 10001

struct 
{
	int S,D,L,T;  
	int next;     //指向相同Source的下一条边
}road[MaxRoad];

int listHead[MaxCity];
bool visited[MaxCity] = {};	//这个城市是否被访问过
int K, N, R, p, minLen = 90000;

void DFS( int thisCity, int thisLen, int restMoney )
{
	if( thisLen > minLen )	//如果当前长度比已知最优解还要长，就回溯
		return;
	if( thisCity==N && restMoney>=0 && thisLen<minLen )	//如果找到了一个更优的解
	{
		minLen=thisLen;
		return;
	}
	for( int i=listHead[thisCity]; i!=-1; i=road[i].next )	//通过邻接表深搜与当前城市相连的所有城市
	{
		int tD = road[i].D;
		int tL = road[i].L;
		int tT = road[i].T;
		if( !visited[tD] && restMoney >= tT )
		{
			visited[tD]=true;
			DFS( tD, thisLen+tL, restMoney-tT );
			visited[tD]=false;
		}
	}
}


int main(void)
{
	cin >> K >> N >> R;
	memset( listHead, -1, sizeof( listHead ) );	//将邻接表的头初始值设为-1
	p=0;	//遍历road用
	for( int i=0; i<R; i++ )	//输入所有的路 
	{
		int s, d, l, t;
		cin >> s >> d >> l >> t;
		road[p].S = s;
		road[p].D = d;
		road[p].L = l;
		road[p].T = t;
		road[p].next = listHead[s];	//这条路的next指向源城市的邻接表头
		listHead[s] = p++;	//源城市的邻接表头换为这个城市
	}
	DFS(1,0,K);
	if( minLen<90000 )
		cout << minLen << endl;
	else cout << -1 << endl;
	return 0;
}