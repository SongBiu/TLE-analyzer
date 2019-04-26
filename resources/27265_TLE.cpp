#include <iostream>
using namespace std;

int rv[14];

int main()
{
	int k;
	while(true)
	{
		cin>>k;
		if( k == 0 ) 
		{
			break;		
		}

		if( rv[k] != 0 ) 
		{			
			cout<<rv[k]<<"\n";			
		}

		int mth = k+1;
		
		while( true )
		{
			// check step
			bool bWrongKill = false;
			int a = 2 * k;
			
			int start = mth % a;			
			if( start == 0 ) start = a;		

			if(start <= k)
			{
				// fisrt kill failed
				mth++;
				continue;
			}

			while( a > k + 1 ) // alive > k
			{
				// kill one
				a--;
				if( start == a+1 ) start = 1;

				// next start

				start = (start + mth - 1) % a;
				if( start == 0 ) start = a;

				if( start <= k )
				{
					// kill good guy
					bWrongKill = true;
					break;
				}
			}
			if( ! bWrongKill ) break;
			mth++;			
		}
		rv[k]=mth;
		cout<<mth<<"\n";
	}
	return 0;
}