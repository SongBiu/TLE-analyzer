#include<iostream>
#include<cstring>
using namespace std;
int a[1000] = {};
int m;
int temp = 1;
int u= 1;
int n2;
int main()
{
	
	while (cin >> n2>> m, m != 0)
	{
		int n = n2;
		while (1) {
			if (n == 1)
				break;
			int i = temp;
			for (; i <= n2; i++)
			{
				if (a[i] == -1&&i!=n2)
					continue;
				if (i == n2&&a[i] == -1)
				{
					i = 0;
					continue;
				}
				if (u == m)
				{
					a[i] = -1;
					int k = i + 1;
					for (; k <= n2; k++)
					{
						if (a[k] != -1)
						{
							temp = k;
							break;
						}
						if (k == n2)
							k = 0;
					}

					if (i == n2)
						temp = 1;
					u = 1;
					n--;
					break;
				}
				if (a[i] != -1) {
					a[i] = u;
					u++;
				}	
			}
		}
		for (int i = 1; i < n2+1; i++)
		{
			if (a[i] != -1)
			{
				cout << i;
				break;
			}
		}
		memset(a, 0, sizeof(a));
		temp = 1;
	}
}
