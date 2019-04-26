#include <iostream>
#include <string>
using namespace std;

bool can(int k,int a)
{
     string list;
     for (int i=0;i<k;i++) list.push_back('g');
     for (int i=0;i<k;i++) list.push_back('b');
     for (int i=0,p=0;i<k;i++)
     {
         if (list[(p+a-1)%list.length()]=='g') return false;
         else list.erase(p=(p+a-1)%list.length(),1);
     }
     return true;
}

int main()
{
    int k,a;
    for (;;)
    {
        cin>>k;
        if (!k) break;
        for (a=1;!can(k,a);a++) ;
        cout<<a<<endl;
    }
}
