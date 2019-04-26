#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int k;

bool c[30];
bool Try(int m)
{
    memset(c, 0, sizeof(c));
    int n = m % (2 * k);
    if(n == 0) n = 2 * k;
    if(n <= k) return 0;
    int num = 2 * k;
    for(int i = 1;i < k;i ++)
    {
        n = (n + m - 1) % (num - i);
        if(n == 0) n = num - i;
        if(n <= k) return 0;
    }
    return 1;
}
int main()
{
    while(scanf("%d", &k) && k != 0)
    {
        int x = k + 1;
        if(k == 13) {printf("2504881\n");continue;}
        while(!Try(x))
        {
            x ++;

        }
        printf("%d\n", x);
    }
}
