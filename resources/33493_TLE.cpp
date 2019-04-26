#include <iostream>
#include <string.h>
using namespace std;

int n;
int m;

int main()
{
    int k;
    while (cin >> k)
    {
        if (!k)
            break;
        int t;
        for (t = k + 1;;t++)
        {
            int num = 2 * k;
            bool flag = true;
            int counter = 0;
            for (int i = 1; i <= k; i++)
            {
                counter = (counter + t - 1) % (num - i + 1);
                if (counter < k)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << t << endl;
                break;
            }
        }
    }
    return 0;
}