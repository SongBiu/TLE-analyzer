// _Z3dfsiii res
#include <iostream>
using namespace std;
int num[101], d[101][300], c[101][300], l[101][300], K, N, R;
int res = 50000;
void dfs(int b, int cnt_cost, int cnt_l){
    //printf("dfs(%d, %d, %d)\n", b, cnt_cost, cnt_l);
    if(cnt_cost > K || cnt_l > res) return ;
    if(b == N){
        if(cnt_l < res) res = cnt_l;
        return ;
    }
    for(int i = 0;i < num[b];i ++){
        dfs(d[b][i], cnt_cost + c[b][i], cnt_l + l[b][i]);
    }
    return ;
}
void ini(){
    for(int i = 1;i <= N;i ++)
        num[i] = 0;
}
int main(){
    cin >> K >> N >> R;
    int x, y, z, k;
    ini();
    while(R --){
        cin >> x >> y >> z >> k;
        d[x][num[x]] = y;
        l[x][num[x]] = z;
        c[x][num[x]] = k;
        num[x] ++;
    }
    dfs(1, 0, 0);
    if(res < 50000) printf("%d\n", res);
    else printf("-1\n");
    return 0;
}