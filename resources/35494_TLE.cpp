#include <iostream>
using namespace std;

int main()
{
	int k;
	do
	{
		cin >> k;
		if(k == 0) break;
		int i = k + 1, j;
		do
		{
			j = 2 * k;
			int t = i % j;
			if(t == 0) t = j;
			do
			{
				if(t <= k) break;
				j--;
				t = (t + i - 1) % j;
				if(t == 0) t = j;
			}while(j > k);
			if(j == k) break;
			i++;
		}while(1);
		cout << i << endl;
	}while(1);
	return 0;
}