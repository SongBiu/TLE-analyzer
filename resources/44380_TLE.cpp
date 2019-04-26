#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

// k: k good guys, k bad guys, max k=14
int k;

bool joseph(int k, int m) {
    int n = k * 2, s = 0, rest;
    for (int i = 1; i <= k; i++) {
        rest = n - i + 1;
        s = (s + m - 1) % rest;
        if (s < k) return false;
    }
    return true;
}

int main() {
    while (cin >> k && k) {
        for (int m = k;; m++) {
            if (joseph(k, m)) {
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}