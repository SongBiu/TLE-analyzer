
// Marchon 20130704
#include<iostream>
#include<string.h>
using namespace std;
bool test(int m,int k)
{
	int peo_left = 2 * k;
	int modulo;
	int cur = 0;
	while(peo_left > k)
	{
		cur = (cur - 1 + m) % peo_left;
		if(cur < k)
			return false;
		peo_left--;
	}
	return true;
}
int main()
{
	int k;
	while(cin >> k)
	{
		if(k == 0)
			return 0;
		if(k == 1)
		{
			cout << 2 << endl;
			continue;
		}
		int m = 0;
		while(!test(++m,k)){}
		cout << m << endl;
	}
	return 0;
}