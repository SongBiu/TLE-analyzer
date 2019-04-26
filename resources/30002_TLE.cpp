#include <stdio.h>
#include <time.h>

int main()
{
#ifdef LOCAL
    freopen("dat.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
#endif
    int k; // the number of good guys / bad guys
    while(scanf("%d", &k) == 1 && k != 0)
    {
        int j;
        for(j = 2; ; j++)
        {
            /* kill the first k guys */
            int rn = 2 * k;
            int flag = 1;
            int last = rn;
            while(rn > k)
            {
                last = ((j % rn) + last - 1) % rn;
                if(last == 0)
                    last = rn;
                if(last < k)
                {
                    flag = 0;
                    break;
                }
                rn--;
            }
            if(flag == 1)
            {
                printf("%d\n", j);
                break;
            }
        } // for()
    } // while()
    //printf("%.4lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
