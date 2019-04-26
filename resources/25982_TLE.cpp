#include<stdio.h>/*存一个比较好的代码吧，算法很好，OJ上能不能过已经不重要了*/

int test(int k, int m)
{
    int i=0, len=2*k;
    while(len>k){
        i=(i+m-1)%len;
        if(i<k) return 0;
        len--;
    }
    return 1;
}

int main()
{
    int m, k;
    while(scanf("%d", &k), k){
        m=k+1;
        while(1){
        if(test(k, m)){
            printf("%d\n", m);
            break;
        }
        else m++;
        }
    }
    return 0;
}
