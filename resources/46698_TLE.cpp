#include <stdio.h>

int main()
{
    int k, m, n, pos = 0;

    while (scanf("%d", &k) && k != 0)
    {
        for (m = k, n = 0; n != k; m++)
        {
            n = 2 * k;
            pos = 0;
            while (n > k)
            {
                pos = (pos + m) % n;
                if (pos < k) break;
                n--;
                pos = (pos == n? 0 : pos);
            }
        }
        printf("%d\n", m);
    }
    return 0;
}