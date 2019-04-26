#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int l = 0;
	int t = 1;
	int n;
	int k;
	int m = 1;
	int z = 0,as=0;
	int sum = 0;
	int b[100];
	int a[100] = {};
	while (cin >> k, k != 0)
	{
		if (k == 1)
			cout << 2 << endl;

		else
		{
			n = 2 * k;
			for (m = k + 1;; m++)
			{
				t = 1;
				for (int j = 1; j < n + 1; j++)
				{
					a[j] = j;
				}
				for (int q = n; q > k; q--)
				{
					int e = m%q;
					if (t == 1 && e == 0)
						l = q;
					if (e + t - 1 <= q && (t != 1 || e != 0))
						l = e + t - 1;
					if (e + t - 1 > q)
						l = e + t - 1 - q;
					
					if (a[l] <= k)
					{
						break; 
					}
					as++;
					{
						for (int p = l; p < n + 1; p++)
						{
							a[p] = a[p + 1];
						}
						a[n] = 0;
					}
					t = l;
				}
				if (a[l] <= k&&as!=k)
					continue;
				int sum = 0;
				for (int o = 1; o <= k; o++)
				{
					sum += a[o];
				}
				if (sum == k*(k + 1) / 2)
				{
					cout << m << endl;
					break;
				}
			}
		}
	}
}