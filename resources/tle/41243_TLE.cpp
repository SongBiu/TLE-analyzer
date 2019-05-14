// _Z3DFSiii minLen
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std ;

struct ROAD
{
	short M ;
	short map[10005] ;
	short cost[10005] ;
	unsigned char des[10005] ;
} road[110] ;

int N ;
int R ;
int dis[110] ;
int toll[110] ;
int minLen = INT_MAX ;
bool v[110] ;


void DFS(int src, int m, int d)
{
	int i ;
	if (m < 0)
		return ;
	if (src == N && d < minLen)
		minLen = d ;
	
	if (v[src])
		return ;
	if (dis[src] && dis[src] <= d && toll[src] >= m)
		return ;

	v[src] = true ;
	dis[src] = d ;
	toll[src] = m ;

	for (i = 0; i < road[src].M; ++i)
		if (road[src].map[i] > 0)
			DFS(road[src].des[i], 
				m-road[src].cost[i], 
				d+road[src].map[i]) ;
	v[src] = false ;
}


int main() 
{
#ifndef ONLINE_JUDGE
	freopen("inn.txt", "r", stdin) ;
#endif
	int K ;
	memset(road, 0, sizeof(road)) ;

	scanf("%d", &K) ;
	scanf("%d", &N) ;
	scanf("%d", &R) ;

	int i, j ;
	for (i = 0; i < R; ++i)
	{
		int S, D, L, T ;
		scanf("%d%d%d%d", &S, &D, &L, &T) ;
		road[S].map[road[S].M] = L ;
		road[S].cost[road[S].M] = T ;
		road[S].des[road[S].M] = D ;
		road[S].M++ ;
	}

	DFS(1, K, 0) ;
	printf("%d\n", minLen<INT_MAX? minLen: -1) ;

	return 0 ;
}