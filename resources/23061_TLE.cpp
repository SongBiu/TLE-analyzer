#include <iostream>
using namespace std;

int 
main()
{
	int k = 0;
	while( cin >> k )
	{
		if( k == 0 )
		{
			break;
		}

		int s = 0;			//location
		int n = 2 * k;		//the number of survivor
		int m = k + 1;
		while(true)
		{
//			s = (s + m) % n;//the next location

/*			for( int i = 0; i < m; i++ )
			{
				s += 1;
				if( s > n ) s = s - n;
			}
			*/
//			cout << "S:" << s << endl << endl;
			s = (s + m - 1) % n;
			if( n > k && s < k )
			{
				++m;
				s = 0;
				n = 2 * k;
/*				cout << "M:" << m << endl;
				cout << "S:" << s << endl;
				cout << "N:" << n << endl << endl;
				*/
				continue;
			}
			if( n > k && s >= k )
			{
				--n;
/*				cout << "N:" << n << endl;
				cout << "S:" << s << endl << endl;
				*/
			}	
			if( n == k )
			{
				cout << m << endl;
				break;
			}
		}

	}
	return 0;
}
