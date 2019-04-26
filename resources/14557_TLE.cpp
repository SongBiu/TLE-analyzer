#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    
    int a[15];
    memset(a,0,sizeof(a));
    while(1)
    {
         int k;
         int m=0;
         cin>>k;
         if(k==0)
            return 0;
         else
         {
             while(1)
             {
                 int all=2*k;
                 int now=0;
                 m++;
                 while(1)
                 {
                     now=(now+m-1)%all+1;
                     if(now>k)
                     {
                         all--;
                         now--;
                     }
                     else
                         break;
                 }
                 if(all==k)
                 {
                     a[k]=m;
                     break;
                 }
             } 
         }
         cout<<a[k]<<endl;
    }
    system("pause");
    return 0;
}
