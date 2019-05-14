// _Z3dfsi min_len
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int K,N,R;  // k总钱数，N城市数，R路数
int total_len;
int total_cost;
int min_len;
int visited[101] = {0};

struct Road
{
	int s; //source
	int d;  // dest 
	int l;  // len
	int t;  // toll
};
vector< vector< Road> > City(101);
void dfs(int s) // 从s到N的最少路径 
{
	if(s == N)
		min_len =  min(min_len,total_len);
	int i,j;
	for(j = 0; j < City[s].size(); j++)
	{
			 int des = City[s][j].d;
		 	 int cost = total_cost + City[s][j].t;
		 	 if(cost > K)
		 	 	continue;
		 	int len = total_len + City[s][j].l; 
			if(len > min_len)
				continue;
			if(visited[des] )
				continue;
			total_len += City[s][j].l;
			total_cost += City[s][j].t;
			visited[des] = 1;
			dfs(des);
			visited[des] = 0;
			total_len -= City[s][j].l;
			total_cost -= City[s][j].t;
	}
}
	
	
	
	

int main()
{
	int i, j;
	cin >> K >> N >> R;

	for(i = 1; i <= R; i++)
	{
		Road temp;
		cin >> temp.s >> temp.d >> temp.l >> temp.t;
		City[temp.s].push_back(temp);		
	}
	total_len = total_cost = 0;
	min_len = 1e10;
	dfs(1);
	cout << min_len << endl;
	while(1)
	return 0;
}
	

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	 

