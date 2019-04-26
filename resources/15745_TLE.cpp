#include <iostream>

using namespace std;


int main()
{
	int k;
	int m,n;
	int cur,next;
	int count;
	while(cin>>k)
	{
		if(k == 0) break;
		for(m = k+1;;m++)
		{
			count = k;
			n = 2*k;
			cur = 1;
			while(count >= 1)
			{
				next = (cur + m - 1) % n;
				if(next == 0) 
				{
					next = n;
					cur = 1;
				}
				else cur = next;
				if(next <= k) break;
				count --;
				n--;
			}
			if(count == 0)
			{
				cout<<m<<endl;
				break;
			}
		}
	}
	return 0;
}
	