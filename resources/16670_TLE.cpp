#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int find(int n, int& m, int step, vector<int> q)
{
	while(step > 0)
	{
		m = (m + 1) % n;
		bool t = true;

		for(int iCnt = 0; iCnt < q.size(); iCnt ++)
		{
			if(m == q[iCnt])
			{
				t = false;
				break;
			}
		}

		if(t)
		{
			step --;
		}
	}
	int k = m;

	//next start pos

	do
	{
		m = (m + 1) % n;
		bool t = true;

		for(int iCnt = 0; iCnt < q.size(); iCnt ++)
		{
			if(m == q[iCnt])
			{
				t = false;
				break;
			}
		}

		if(t)
			break;
	}while(true);

	return k;
}

int main()
{
	int n;
	int m;
	vector<int> q;
	vector<int> result;

	while(true)
	{
		cin >> n;
		if(!n)
			break;

		m = n + 1;
		bool t = true;

		do
		{
			int tt = 0;
			int iCnt = 0;
			for(iCnt = 0; iCnt < n; iCnt ++)
			{
				int i = find(n * 2, tt, m - 1, q);
				q.push_back(i);
				if(i + 1 <= n)
				{
					t = false;
					break;
				}
			}
			
			q.clear();
			if(iCnt == n)
			{
				t = true;
				break;
			}


			m ++;
		}while(!t);

		result.push_back(m);
	}
	
	for(int iCnt = 0; iCnt < result.size(); iCnt ++)
	{
		cout << result[iCnt] << endl;
	}

	return 0;
}