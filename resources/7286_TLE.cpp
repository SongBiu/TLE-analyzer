#include <iostream>
#include <memory>
using namespace std;
int main() {
    int k, t, m, i, j, w;
    int a[40];
    bool f;
    while (cin >> k) {
        if (k == 0)
            break;
        for (m = k;; m++) {
            f = 1;
            j = 0;
            memset(a, 0, sizeof(a));
            for (i = 1; i <= k; i++) {
                for (w = 1; w <= m % (2 * k - i + 1) + 2 * k - i + 1; w++) {
                    t = j + 1;
                    if (t == 2 * k + 1)
                        t = 1;
                    for (j = t; a[j] == 1; j++)
                        if (j == k * 2)
                            j = 0;
                }
                if (j <= k) {
                    f = 0;
                    break;
                } else
                    a[j] = 1;
            }
            if (f)
                break;
        }
        cout << m << endl;
    }
    return 0;
}