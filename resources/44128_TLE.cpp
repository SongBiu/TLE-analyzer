#include <iostream>
using namespace std;
bool calc(int k, int m)
{
	int i,j;
	int now,next,total;
	bool res=1;
	int* mat = new int[2*k];
	for (i = 0; i < 2 * k-1; i++)
	{
			mat[i] = i + 1;
	}
	mat[2 * k - 1] = 0;
	total = 2 * k;
	now = 0;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < ((m - 2)%total); j++)
		{
			now = mat[now];
		}
		next = mat[now];
		if ((next < k) && (next >= 0))
		{
			res = 0;
			return res;
		}
		next = mat[next];
		mat[now] = next;
		now = next;
		total--;
	}
	delete[] mat;
	return res;
}

int main()
{
	int k,minm,p;
	int result[13];
	for (p = 1; p < 14; p++)
	{
		minm = p + 1;
		while (calc(p, minm) == 0)
		{
			minm++;
		}
		result[p - 1] = minm;
	}


	cin >> k;
	while (k != 0)
	{
		cout << result[k - 1] << endl;
		cin >> k;
	}
	return 0;
}