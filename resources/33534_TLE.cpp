#include<iostream>
using namespace std;
int main()
{
	int k;
	while (cin >> k)
	{
		if (k == 0) break;
		int m;
		for (m = k; ; m++)
		{
			int curchildren = k + k;
			int id = 0;
			for (; curchildren > k; curchildren--)
			{
				id += (m - 1);
				id %= curchildren;
				if (id < k) break;
			}
			if (curchildren == k)
			{
				cout << m << endl;
				break;
			}
		}
	}
	return 0;
}