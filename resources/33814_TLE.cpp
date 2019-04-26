#include <iostream>
using namespace std;
int main()
{
    int k;
    while (cin >> k)
    {
        if (k == 0)
            break;
        int total = 2 * k, m = total - 1;
        while (1)
        {
            int tmp, i = 0, pian = 0, total = 2 * k;
            while (i < k)
            {
                tmp = m % (total - i);
                if (tmp == 0)
                    tmp = total - i;
                if (tmp <= k + pian && tmp >= 1 + pian)
                    break;
                if (tmp <= pian)
                    pian -= tmp;
                else
                    pian = total - i -(tmp - pian);
                i++;
            }
            if (i == k)
            {
                cout << m << endl;
                break;
            }
            m++;
        }
    }
    return 0;
}