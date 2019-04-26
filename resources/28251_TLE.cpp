#include <stdio.h>
int main()
{
    int m,n,i,j,k,t,p ;
    int a[65535] ;
    while(1)
    {
        scanf("%d",&k) ;
        if (k != 0)
        {
            n = 2 * k ;
            for (m = 2; ; m++)
            {
                int flag = 1 ;
                for (i = 0; i < n; i++)
                    a[i] = 1 ;
                p = k ;
                for (i = 0,t = 0; p > 0; t = (t + 1) % m)
                {
                    j = i ;
                    while (a[j] == -1)
                        j = (j + 1) % n ;
                    a[j] = t ;
                    if (t == m - 1)
                        if (j < k)
                        {
                            flag = 0 ;
                            p = 0 ;
                        }
                        else
                        {
                            p-- ;
                            a[j] = -1 ;
                        }
                    i = (j + 1) % n ;
                }
                if (flag == 1)
                    break ;
            }
            printf("%d\n",m) ;
        }
        else
            break ;
    }

    return 0 ;
}