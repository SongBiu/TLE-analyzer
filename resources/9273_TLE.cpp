#include <iostream>
using namespace std;
int main()
{
    int b,i,j,pos,m,k,c,n;
    bool r[28],y;
    while(cin >> k)
    {
        if(!k) break;
        b = 0;
        m = k-1;
        while(b!=k)
        {
            n = k;
            b = 0;
            m++;
            for(i=0;i<28;i++) r[i] = true;
            y = true;
            pos = 1;
            c = 1;
            while(n&&y)
            {
                while(1&&y)
                {
                    if(r[pos]&&c%m==0)
                    {
                        r[pos] = false;
                        if(pos<=k) y = false;
                        else b++;
                        n--;
                        pos++;
                        if(pos>2*k) pos = 1;
                        c = 1;
                        break;
                    }
                    else
                    {
                        if(!r[pos])
                        {
                            if(pos==2*k) pos = 0;
                            pos++;
                        }
                        else
                        {
                            if(pos==2*k) pos = 0;
                            pos++;
                            c++;
                        }
                    }
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}
