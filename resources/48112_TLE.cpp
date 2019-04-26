#include <iostream>
#include <vector>
using namespace std;
int main() {
	while (1) {
		int k;
		cin >> k;
		if (k == 0)
			break;
		vector<bool> isGood(k + k, false);
		for (int i = 0; i < k; i++)
			isGood[i] = true;
		int tryNum = k + 1;
		bool f = false;
		int b = 0;
		while (1) {
			for (tryNum = k + 1 + 2 * k*b; tryNum <= 2 * k + 2 * k*b; tryNum++) {
				vector<bool> tmp = isGood;
				int p = tryNum % (tmp.size());
				bool suc = true;
				for (int i = 0; i <= k + 1; i++, p = (p + tryNum - 1) % (tmp.size())) {
					if (p == 0)
						p = tmp.size();
					if (!tmp[p - 1]) {
						tmp.erase(tmp.begin() + p - 1);
						continue;
					}
					else
						for (int j = 0; j < tmp.size(); j++)
							if (!tmp[j]) {
								suc = false;
								break;
							}
					if (!suc)
						break;
				}
				if (!suc) {
					continue;
				}
				else {
					cout << tryNum << endl;
					f = true;
					break;
				}
			}
			if (f)
				break;
			b++;
		}
	}
}