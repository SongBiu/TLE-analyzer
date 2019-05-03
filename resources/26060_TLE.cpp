#include <iostream>
#include <cstring>
using namespace std;

 

int p[100];
int work(int k, int m)
{
	int i;
	int pos = 0;
	int sum = 2 * k;
	for(i = 0;i < k;i++)
	{
		pos = (pos + m - 1) % sum;
		if (pos < k)
			return 0;
		sum--;
	}
	return 1;
}

int main()
{
	int a;
	int ans;
	int ok, i;
	while(cin >> a, a)
	{
		ok = 0;
		for(i = 0;;i++)
		{
			for(ans = a + 1;ans <= a * 2;ans++)
			{
				memset(p, 0, sizeof(p));
				if (work(a, ans + i * 2 * a))
				{
					ok = 1;
					break;
				}
			}
			if (ok)
				break;
		}

		cout << ans + i * 2 * a << endl;
	}
	return 0;
}