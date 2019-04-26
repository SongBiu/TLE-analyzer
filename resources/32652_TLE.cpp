#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline int check(int k, int m)
{
    int q=0, i=0, b=1, n=k+k, t1=1<<k, t2=t1<<k, j;
    m--; j=m%n;
    while(n>k)
    {
        if(i==j) { if(b<t1) return 0; q|=b; i=0; n--; j=m%n; } else i++;
        do{ b<<=1; if(b&t2) b=1; } while(b&q);
    }
    return 1;
}

int find(int k)
{
    int M=(k+1)*(k+2);
    int x[6] = { k+2, k+k+3, k*(k+1), (k+1)*(k+1), M, M+1 };
    int i;
    while(1)
    {
        for(i=0;i<6;i++)
        {
            if(check(k, x[i])) return x[i];
            x[i]+=M;
        }
    }
}

int main()
{
    int k = 0;
    while(scanf("%d", &k) && k)
    {
        printf("%d\n", k<14? find(k):0);        
    }
    return 0;
}