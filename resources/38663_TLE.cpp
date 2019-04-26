#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int k;
int a[28];
bool Josephus(int m) {
	for (int i = 1; i <= k; i++) {
		a[i] = (a[i - 1] + m - 1) % (2 * k - i + 1);
		if (a[i] < k) return false;
	}
	return true;
}
int main(){
	int m;
	while (cin >> k) {
		if (k == 0) break;
		m = k + 1;
		memset(a, 0, sizeof(a));
		while(!Josephus(m))
			m++;
		cout << m << endl;
	}
	return 0;
}