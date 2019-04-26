#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int a[100];
int n,k;
bool checker(int m)
{
     for (int i = 1; i <= 2*k;++i)
              a[i] = i;
     for (int i = 0; i < k;++i)
     {
         int p = (m-1)%(2*k-i)+1;
         int temp = a[p];
         if (temp<=k) return false;
         for (int j = 1; j<p;++j) a[2*k-i+j]= a[j];
         for (int j = 1;j<=2*k-i-1;++j) 
             a[j] = a[j+p];
     }     
     return true;
}
int main()
{
    while (cin>>k && k){
      
      int m = k+1;
      while (!checker(m)) m++;
      cout<<m<<endl;
    
    }
    return 0;
}