#include<iostream>
#include<cstring>
using namespace std;

int a[30], mark[30], ret[30], k, n;

bool check(int m) {
     int start = 1, out, step;
     memset(mark, 0, sizeof(mark));
     for (int i = 0; i < k; i ++)  {
         step = m % (n - i);
         if (step == 0)  step = n - i;
         out = start;
         while (step)    {
               if (mark[out] == 0)  step --;
               out ++;
               out %= n;
         }
         out --;   out = (out + n) % n;
         if (out >= 1 && out <= k) return false;
         mark[out] = 1;
         start = out + 1;
         start %= n;
         while (mark[start] != 0)      {
               start ++;
               start %= n;
         }
     }
     return true;
}

int main()      {
    while (cin >> k && k != 0)  {
          n = 2 * k;
          int m = k + 1;
          while (!check(m))  m ++;
          cout << m << endl;
    }
    return 0;
}
