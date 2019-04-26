#include <iostream>

using namespace std;

//A: 65, a: 97

int calc(int k, int m) {
	int n = 2 * k;
	int kill, tmp = m%n;
	if (tmp == 0)
		kill = n;
	else
		kill = tmp;
	int remain = (n--) - kill;
	for (; n > k;) {
		tmp = (m - remain) % n;
		if (tmp == 0)
			kill = n;
		else
			kill = tmp;
		if (kill <= k)
			return false;
		remain = (n--) - kill;
	}
	return true;
}

int main() {
	int k, flag;
	for (cin >> k; k; cin >> k) {
		flag = k + 1;
		for (;; flag++) {
			if (calc(k, flag)) {
				cout << flag << endl;
				break;
			}
		}
	}
	return 0;
}
