#include<iostream>
using namespace std;
int joseph(int k, int m)
{
	int i, j;
	for (i = k; i >0; i--)
	{
		int temp;
		int survive = 2 * k + 1 - i;
		if (m%survive == 0) temp = survive - 1;
		else temp = m%survive - 1;
		for (j = 0; j < i - 1; j++)
		{
			temp = (temp + m) % (survive + 1);
			survive++;
		}
		if (temp < k) return 0;
	}
	return 1;
}
int main()
{
	int k;
	while (cin >> k)
	{
		if (k == 0) break;
		int m;
		for (m = k + 1;;m++)
		{
			if (joseph(k, m) == 1)
			{
				cout << m << endl;
				break;
			}
		}

		
			
	}
	return 0;
}