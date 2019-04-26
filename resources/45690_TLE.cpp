#include <iostream>
#include <string>
#include <list>
#include<cstdlib>
#include <cstring>
using namespace std;
// 1 2 3 4 5 6
bool des_bad(int n, int m){
	int r = 1;
	int flag[n + 1];
	memset(flag, 0, sizeof(int) * (n + 1));
	int count = 0;
	int x = 1;
	while(count < n / 2){
		while(flag[r] == 1)
		{
			r++;
			if (r == n + 1)
		    {
			    r = 1;
		    }
		}
		if (r == n + 1)
		{
			r = 1;
		}
		if(x % m == 0){
			if (r <= n / 2)
			{
				return false;
			}
			flag[r] = 1;
			count += 1;
		}
		r++;
		x++;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n && n != 0){
		for (int i = n + 1; ; ++i)
		{
			if (i % (2 *n) <= n)
			{
				continue;
			}
			if(des_bad(2 * n, i)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}