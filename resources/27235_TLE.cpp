#include <iostream>

using namespace std;

int main()
{
	int k , n , m , begin ;
	while(cin>>k)
	{
		if(k==0)
			break;
		m = k + 1 ;
		while(1)
		{
			n = k * 2;
			begin = 1 ;
			while(n>k)
			{
				if(begin == 0)
					begin = (begin + m) % n ;
				else
					begin = (begin + m -1 ) % n;
				if(begin==0)
				{
					n--;
					continue ;
				}
				if(begin>k)
					n--;
				else
					break;
			}
			if(n==k)
			{
				cout<<m<<endl;
				break;
			}
			m ++;
		}
	}


	return 0;
}