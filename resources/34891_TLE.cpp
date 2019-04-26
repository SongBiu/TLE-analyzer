#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

//1,2,....2n
int main()
{
     int n;
     while (cin>>n)
     {
          if (n==0)break;

          for (int t=1;;t++)//一次过t个
          {
               //cout<<t<<endl;
               int live[30]={0};
               int pos=0,l=2*n,gtn,fail=0;
               while (l>n)
               {
                    gtn=(t-1)%l+1;
                    for (int i=0;i<gtn;i++)
                    {
                         pos++;
                         if (pos>2*n)pos=1;
                         while (live[pos]!=0)
                         {
                              pos++;
                              if (pos>2*n)pos=1;
                         }
                    }
                    if (pos<=n)
                    {
                         fail=1;
                         break;
                    }
                    //cout<<pos<<endl;
                    live[pos]=1;
                    l--;
                    //pos++;
                    //if (pos>2*n)pos=1;
               }
               if (fail==0)
               {
                    cout<<t<<endl;
                    break;
               }
               if (t%(2*n)==0)
                    t=t+n;
          }
     }
}
