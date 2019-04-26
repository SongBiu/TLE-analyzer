#include <iostream>
using namespace std;

int main()
{
	bool isOK(int k,int sgn);
	int k;
	int sgn;
	while ((cin >> k)&&k!=0) {
		sgn = k + 1;
		while (1) {
			if (isOK(k,sgn)) {
				cout << sgn << endl;
				break;
			}
			sgn++;
		}
	}
    return 0;
}
bool isOK(int k,int sgn) {
	int n = 2 * k;
	int pos = 0;
	for (int i = 1; i <= k; i++) {
		pos = (pos + sgn-1) % (n - i + 1);
		if (pos < k) return false;
	}
	return true;
}