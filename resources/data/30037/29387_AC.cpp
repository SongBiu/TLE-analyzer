#include <stdio.h>
#include <memory.h>

const int INF = 10000000;

int K, N, R;
int next[10005], head[10005];
int s[10005],d[10005],l[10005],t[10005];
bool arrived[101];
int min = INF;

int dfs(int des, int money, int len){
    if (len >= min || money < 0)  return INF+1;
    if (des == 1){
        min = len;
        return 0;
    }
    int min = INF, i, tmp;
    for (i = head[des]; i >= 0; i = next[i]){
        if (arrived[s[i]]) continue;
        arrived[s[i]] = true;
        tmp = dfs(s[i], money-t[i], len + l[i]) + l[i];
        arrived[s[i]] = false;
        if (tmp < min) min = tmp;
    }
    return min;
}

int main (){
    scanf("%d%d%d", &K,&N,&R);
    memset(head, -1, sizeof(head));
    memset(arrived, false, sizeof(arrived));
    for (int i = 0; i < R; i++){
        scanf ("%d%d%d%d", s+i, d+i, l+i, t+i);
        next[i] = head[d[i]];
        head[d[i]] = i;
    }
    printf("%d", dfs(N, K, 0));
    return 0;
}