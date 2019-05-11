// _Z3dfsi minLen
#include <iostream>
using namespace std;

int K, N, R;
int curLen = 0, minLen = 1 << 30;
int s[10003], e[10003], l[10003], t[10003];

void dfs(int num) {
    if(num == N) {
        minLen = min(minLen, curLen);
        return;
    }
    
    for(int i = 0; i < R; i ++)
        if(s[i] == num) {
            if(curLen + l[i] >= minLen)
                continue;
            if(K - t[i] >= 0) {
                curLen += l[i];
                K -= t[i];
                dfs(e[i]);
                curLen -= l[i];
                K += t[i];
            }
        }
}

int main() {
    cin >> K >> N >> R;
    for(int i = 0; i < R; i ++) {
        cin >> s[i] >> e[i] >> l[i] >> t[i];
    }
    dfs(1);
    
    if(minLen == 1 << 30)
        minLen = -1;
    cout << minLen << endl;
}
