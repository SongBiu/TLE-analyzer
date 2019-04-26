#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
    int k;
    while(cin>>k && k!=0)
    {
        int m=k+1;
        while(1)
        {
            int start=1,number=2*k;
            bool complete=true;
            for(int i=1;i<=k;i++)
            {
                int del=(start+m-1)%number;
                if(del>=1 && del<=k)
                {
                    complete=false;
                    break;
                }
                number--;
                (del==0)?start=1:start=del;
            }
            if(complete)
            {
                cout<<m<<endl;
                break;
            }
            m++;
        }
    }
}