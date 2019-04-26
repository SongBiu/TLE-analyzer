#include<iostream>
using namespace std;
int k = 0, t = 0;
int dfs(int n,int p,int m) {
	if (n == k)return 1;
	int l,dead;
	l = m%n;
	dead = l - 1 + p;
	if (dead == 0)dead = n;
	if (dead > n)dead -= n;
	if (dead <= k)return 0;
	return dfs(n - 1, dead > n - 1 ? dead - n + 1 : dead, m);
}
int main() {
	while (cin >> k) {
		if (k == 0)break;
		t = k * 2;
		int mm = k, re = 0;
		while (++mm) {
			re=dfs(t,1, mm);
			if (re == 1) {
				cout << mm << endl;
				break;
			}
		}
	}
	return 0;
}