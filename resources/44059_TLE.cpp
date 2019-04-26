#include <iostream>
#include <list>
using namespace std;
int main()
{
	cin.sync_with_stdio("false");
	int k;
	cin >> k;
	while (k)
	{
		int m = k;
		while (true)
		{
			++m;
			int badcount = 0;
			list<int> l;
			for (int i = 0; i < 2 * k; ++i)
				l.push_back(i);
			list<int>::iterator cur = l.begin();
			int count = 1;
			while (true)
			{				
				if (cur == l.end())
					cur = l.begin();
				if (count == m)
				{
					if (*cur < k)
						break;
					else
					{
						badcount++;
					}
					cur = l.erase(cur);
					if (cur == l.end())
						cur = l.begin();
					count = 1;
				}
				else
				{
					++cur;
					++count;
				}
			}
			if (badcount == k)
			{
				cout << m << endl;
				break;
			}
		}
		cin >> k;
	}
	//system("pause");
	return 0;
}