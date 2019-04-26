#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<bool> s;
	list<bool>::iterator t;
	int k, m;
	cin >> k;
	while(k != 0)
	{	
		for (m = 1; 1; ++ m)
		{
			if (!s.empty())
			s.clear();
			for (int i = 1; i <= k; ++ i)
				s.push_back(0), s.push_front(1);
			t = s.begin();
			int i = 1;
			for (; i <= k; ++ i)
			{				
				int num = s.size();
				num = m % num;
				if (num == 0)
				{
					if (t == s.begin())
						t = s.end();
					t --;
				}
				for (int j = 1; j < num; ++ j)
				{
					++ t;
					if (t == s.end())
						t = s.begin();
				}
				if (*t)
					break;
				t = s.erase(t);
				if (t == s.end())
					t = s.begin();
			}
			if (i == k + 1)
				break;
		}
		cout << m << endl;
		cin >> k;
	}
	return 0;
}