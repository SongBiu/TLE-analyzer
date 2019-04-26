#include <iostream>
using namespace std;
int k;
int m;
bool kill(int start, int bad)
{
	if(bad == 0)
		return true;
	else if((start + m - 1) % (k + bad) < k)
		return false;
	else
		return kill((start + m - 1) % (k + bad), bad - 1);
}
int main()
{
	while(true)
	{
		cin >> k;
		if(k == 0)
			break;
		for(m = k + 1; ;)
		{
			if((m - 1) % (k + k) == 0)
			{
				m += k;
			}
			else if(kill(0, k))
			{
				cout << m << endl;
				break;
			}
			else
				m ++;
		}
	}
	return 0;
}