#include<iostream>   
#include<cmath>   
#include<algorithm>  
#include <fstream>
#include <memory>
#include <cstring> 
using namespace std; 
int main()  
{
 int i, j, a[28], s, k, m;
 int size;
 cin >> k;
 while (k)
 {
  for (i =0 ;i <= 2*k; i++) a[i] = i;
  for (m = 1; ; m++)
  {
	i = m*(k + 1);
	bool is = true;
   s = 1;
   for (size = 2 * k; size > k; size--)
   {
    s = (s - 1 + i) % size;
    if (s == 0) s = size;
    if (a[s] <= k)
    {
     is = false;
     break;
    }
    for (j = s; j < size-1; j++) a[j] = a[j+1];
   }
   if (is == true) 
   {
    cout << i << endl;
    break;
   }
  i++;
	is = true;
   s = 1;
   for (size = 2 * k; size > k; size--)
   {
    s = (s - 1 + i) % size;
    if (s == 0) s = size;
    if (a[s] <= k)
    {
     is = false;
     break;
    }
    for (j = s; j < size-1 ; j++) a[j] = a[j+1];
   }
   if (is == true) 
   {
    cout << i << endl;
    break;
   }
  }
  cin >> k;
 }
   return 0;  
} 

 