#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
bool search( int n , int m )
{
	int i , j = 0 , sum = n<<1;
	for( i = 0 ; i < n ; i ++ )
	{
		j = ( j + m - 1 ) % ( sum - i );//Joseph公式
		if( j < n )
			return 0;
	}
	return 1;
}
int Judge( int n )
{
	int m = n + 1;
	while(1)
	{
		if( search( n , m ) )
			return m;
		if( search( n , m + 1 ) )
			return m + 1;
		m += ( n + 1);//测试数据剪枝
	}
}
int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if( n == 0 )
			break;

		cout << Judge( n ) << endl;
	}
	return 0;
}