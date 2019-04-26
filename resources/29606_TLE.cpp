#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
int work(int n)
{
	int m, cnt = 0, t = 0, cnt2;
	bool sign[50], f;
	for(m = 1; m <= 1000; ++m)
	{
        for(int i = 0; i < 50; ++i)
            sign[i] = false;
		t = 0;
		f = false;
		cnt = 0;
		cnt2 = 0;
		while(f == false && cnt < n / 2)
		{
			t++;
			if(t > n)	t = 1;
			if(sign[t] == false)
			{
				cnt2++;
				if(cnt2 == m)
				{
					sign[t] = true;
					cnt2 = 0;
					if(t > n / 2)
					{
						cnt++;
					}
					else    f = true;
				}
			}
		}
		if(f == false){
			return m;
		}
	}
}
int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
	int k;
	while(cin >> k)
	{
		if(k == 0)  break;
		cout << work(2 * k) << endl;
	}
	return 0;
}
