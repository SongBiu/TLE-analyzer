#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int Joseph[14] = { 0 };

	int k;
	while (scanf("%d", &k))
	{
		if (!k)
			break;

		if (Joseph[k])
		{
			printf("%d\n", Joseph[k]);
			continue;
		}

		int n = 2 * k;
		int ans[30] = { 0 };

		int m = 1;
		while (true)
		{
			for (int i = 1; i <= k; i++)
			{
				ans[i] = (ans[i - 1] + m - 1) % (n - i + 1);
				if (ans[i] < k)
				{
					m++;
				}
			}
		}
		Joseph[k] = m;
		printf("%d\n", m);
	}
	return 0;
}