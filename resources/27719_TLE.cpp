#include <iostream>

using namespace std;

int Judge(const int &k, const int &m)
{
    int s = 0;
    int n = 2 * k;

    for(int i = 0; i < k; ++i)
    {
        s = (s + m - 1) % (n - i);
        if(s < k)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int k;
    while(cin >> k, k)
    {
       for(int m = k + 1, i = 1; ; m *= i, ++i)
       {
           if(Judge(k, m))
           {
               cout << m << endl;
               break;
           }
           if(Judge(k, m + 1))
           {
               cout << m + 1 << endl;
               break;
           }
       }
    }

    return 0;
}
