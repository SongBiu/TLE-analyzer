#include<iostream>
using namespace std;
int main()
{
	int k;
	while (cin >> k&&k != 0)
	{
		int pstart = 1, pnext, cnt = 0, ptotal = k * 2, ans = k + 1;
		while (1)
		{
			pnext = pstart + ans - 1;
			pnext %= ptotal;
			if (pnext == 0 || pnext > k)
			{
				cnt++;
				if (cnt == k)
					break;
				ptotal--;
				if (pnext == 0)
					pstart = 1;
				else
					pstart = pnext;
			}
			else
			{
				pstart = 1;
				cnt = 0;
				ptotal = k * 2;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}