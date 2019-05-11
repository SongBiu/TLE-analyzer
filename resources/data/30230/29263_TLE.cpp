// _Z4moveiiii minlen
#include<iostream>
#include<memory.h>
using namespace std;
int n;//city number
int minlen = 99999999;
int covercity[110] = {0},coverroad[10010] = {0};//0表示没走过，1表示走过
class Road;
class City
{
public:
	Road *go;
	int n;
	int num;
	City()
	{
		n = 0;//roads number that can go
		go = NULL;
	}
};
class Road
{
public:
	int toll,lenth;
	int num;
	City source, dest;
};
City *city;
Road * road;
bool move(int rn,int cn,int mleft,int cov)//rn road编号这步走此路，到达cn city 编号，mleft剩下的钱,cov已走过的长度
{
	if (city[cn].n == 0 && cn != n) return false;//无路可走(可走路数量为0)　　　必须不是最后一个城市！！！
	if ( cov > minlen) return false;
	if ( mleft < 0) return false;//钱不够了
	if ( cn == n)
	{ 
		if (minlen > cov) minlen = cov;
		return true;
	}//钱没用完，没到目的地时
	if (covercity[cn] == 1 || coverroad[rn] == 1)
		return false;//走过的不再重复
	//cout << coverroad[5] << endl;
	//cout << city[1].n << endl;
	covercity[cn] = coverroad[rn] = 1;//走过之后
	int i, n = city[cn].n;	
	//cout << "city" <<cn<<"cover"<<cov<<"moneyleft"<<mleft<<endl;
	int gogo = 0;
	for ( i = 1; i <= n; i ++)
	{
		Road t = city[cn].go[i];//要走的路
	//	cout <<"road number" <<t.dest.num  << endl;
		if ( move(t.num ,t.dest.num,mleft - t.toll,cov+t.lenth) )//可以到达city n
			gogo = 1;
	}
	covercity[cn] = coverroad[rn] = 0;//回溯
	if ( gogo == 1) return true;
	return false;
}
int main()
{
	int i,s,d,l,t;
	int k;//coins
	int r;//road
	int total;//total tolls	
	cin >> k >> n >> r;
	
	city = new City[n+1];//城市编号从1到n
	for ( i = 1; i <= n; i ++)
		city[i].num = i;
	road = new Road[r+1];//编号从1到r
	for ( i = 0; i <= r; i ++)
		road[i].num = i;
	road[0].dest = city[1];road[0].lenth = 0;road[0].toll = 0;//从road[0]开始走
	for (i = 1; i <= r; i ++ )//每个城市的go数组记录了可走的road，每一个road记录了s,d,l,t
	{
		cin >> s >> d >> l >> t;
		road[i].source = city[s];
		road[i].dest = city[d];
		road[i].lenth = l;
		road[i].toll = t;
		if (city[s].go != NULL)
		{
			Road *rr = NULL;//临时变量
			rr = new Road[city[s].n +2];
			for (int i = 1; i <= city[s].n; i++)//数量为n,但是go大小应为n+1，new的一个应该是n+2
			{
				rr[i].dest = city[s].go[i].dest ;
				rr[i].lenth = city[s].go[i].lenth ;
				rr[i].num = city[s].go[i].num ;
				rr[i].source = city[s].go[i].source ;
				rr[i].toll = city[s].go[i].toll ;
			}
			rr[city[s].n +1] = road[i];
			city[s].n ++;
			delete []city[s].go;//动态分配内存
			city[s].go = new Road[city[s].n + 1];
			for (int i = 1; i <= city[s].n; i++)
			{
				city[s].go[i].dest = rr[i].dest ;
				city[s].go[i].lenth = rr[i].lenth ;
				city[s].go[i].num = rr[i].num;
				city[s].go[i].source = rr[i].source;
				city[s].go[i].toll = rr[i].toll ;
			}
			delete []rr;
		}
		else
		{
			city[s].go = new Road[2];
			city[s].go [1] = road[i];
			city[s].n ++;
		}
	}
	int nn = -1;
	if ( move(0,1,k,0) )
		cout << minlen << endl;
	else
		cout << nn << endl;
//	system("pause");
	return 0;
}