#include <stdio.h>
#include <string.h>
#include <memory.h>

int main()
{
    int people[14];
    int k;
    int m;
    int n;
    int kill;
    while ((scanf("%d", &k)) && (k != 0))
    {
        m = k + 1;
        n = 2 * k;
        kill = 0;
        for (int i = 1; i <= k; i++)
        {
            kill = (kill + m - 1) % (n - i + 1);

            if (kill < k)
            {
                i = 0;
                m++;
                kill = 0;
            }
        }

        printf("%d\n", m);
    }

    return 0;
}