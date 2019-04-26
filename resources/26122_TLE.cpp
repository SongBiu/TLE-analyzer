#include<iostream>
#include<memory.h>
using namespace std;

int main()
{
	int temp;
	while( cin >> temp && temp )
	{
		int F[ 2 * temp ];
		for( int i = temp; ; i ++ )
		{
			int number = temp, can = 1, symbol = 0;
			memset( F, 0, sizeof( F ) );
			while( number -- )
			{
				int temp1 = 0;
				while( 1 )
				{
					if( !F[ symbol % ( 2 * temp ) ] ) temp1 ++;
					if( temp1 == i ) break;
					symbol ++;
				}
				F[ symbol % ( 2 * temp ) ] = 1;
				if( symbol % ( 2 * temp ) >= 0 && symbol % ( 2 * temp ) < temp )
				{
					can = 0;
					break;
				}
			}
			if( can )
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}