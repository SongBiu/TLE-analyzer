#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool execute(unsigned int m, unsigned int k)
{
	unsigned int curCount = k << 1;
	unsigned int start = 0;
	while (curCount > k)
	{
		int executedID = (m + start) % curCount;
		if (executedID <= k && executedID != 0)
			return false;
		--curCount;
		start = executedID ? executedID - 1 : 0;
	}
	return true;
}

unsigned int getMinM(unsigned int k)
{
	unsigned int m = k + 1;
	while (1)
	{
		if (m % k << 1 < k) continue;
		if (execute(m, k)) return m;
		if (execute(m + 1, k)) return m + 1;
		m += (k+1);
	}
	return m;
}

int main()
{
	vector<unsigned int> res;
	int k;
	cin >> k;
	while (k > 0)
	{
		res.push_back(getMinM(k));
		cin >> k;
	} 
	for (vector<unsigned int>::iterator itr = res.begin(); itr != res.end(); itr++)
		cout << *itr << endl;
	return 0;
}