// _Z3Dfsi minlen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Rode{
    int dcity ;
    int length ;
    int toll ;
}a[110][110] ;
int minlen = 1 << 30 ;
int nowlen ;
int sumcost ;
int visited[110] ;
int money ;
int n ;
void Dfs(int k)
{
    if( k == n){
        minlen = (minlen < nowlen)? minlen : nowlen ;
        return ;
    }
    int i = 0 ;
    while(a[k][i].dcity != 0 ){
        i++ ;
    }
    for(i--; i >=0 ; i--){
        int d = a[k][i].dcity ;
        if(!visited[d] && (a[k][i].toll+sumcost) <= money){
            if((a[k][i].length + nowlen) >= minlen){
                continue ;
            }
            nowlen += a[k][i].length ;
            sumcost += a[k][i].toll ;
            visited[d] = 1 ;
            Dfs(d) ;
            nowlen -= a[k][i].length ;
            sumcost -= a[k][i].toll ;
            visited[d] = 0 ;
        }
    }
}

int main(void)
{
    int sc , dc , R ,l ,c ;
    scanf("%d%d%d",&money, &n , &R) ;
    for(int i = 0 ; i < R ; i++){
        scanf("%d %d %d %d",&sc , &dc , &l ,&c) ;
        int k = 0 ;
        while(a[sc][k].dcity != 0){
            k++ ;
        }
        a[sc][k].dcity = dc ;
        a[sc][k].length = l ;
        a[sc][k].toll = c ;
    }
    visited[1] = 1 ;
    Dfs(1) ;
    if(minlen < (1 << 30)){
        printf("%d",minlen) ;
    }
    else{
        printf("-1") ;
    }
    return 0 ;
}
