#include<iostream>

using namespace std;

int main()
{
	int k;
	int a[30];
	int m,n;
	int joseph[14] = { 0 };

	while (cin >> k && k)
	{
		if (joseph[k])
		{
			cout << joseph[k] << endl;
		}
		n = 2 * k;
		m = k + 1;
		a[1] = (m - 1) % n;
		
		for (int i = 1;i < k;++i)
		{
			a[i + 1] = (a[i] - 1 + m) % (n - i);
			while (a[i + 1] < k)
			{
				++m;
				a[1] = (m - 1) % n;
				i = 0;
			}
		}
		joseph[k] = m;
		cout << m << endl;
	}
	return 0;
}
