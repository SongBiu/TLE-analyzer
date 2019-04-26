#include<iostream>
using namespace std;
int main()
{
	int g[30];
	int n, k, i, j, m, p;
	while (cin >> k, k != 0)
	{
		for (m = k + 1; ; m ++ )
		{
			for (i = 0; i < k * 2; i ++)
				g[i] = i;
			p = 0;
			for (i = 0; i < k; i ++)
			{
				p = (m - 1 + p) % (k * 2 - i);
				if (p < k) break;
				for (j = p; j < k * 2 - i; j ++)
					g[j] = g[ j + 1 ];
			}
			if (i == k)
				break;
		}
		cout << m << endl;
	}
	return 0;
}
