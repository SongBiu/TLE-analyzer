#include<iostream>
using namespace std ;
int work ( int k, int m )
{
  int flag = 0 ;
  int a[14] ;
  a[0] = 0 ;
  int i ;
  for ( i = 1 ; i <= k ; i++ )
    {
     a[i] = (a[i-1]+m-1)%(2*k-i+1) ;
     if ( a[i] < k ) break ;
    }
  if ( i == k+1 ) flag = 1 ;
  return flag ;
}
int main ()
{
    int k ;
    while ( ( cin >> k ) && k > 0 )
       {
         for ( int j = 1 ; ; j++ )
          {
           if ( work ( k, j*(k+1) ) ) 
             {
               cout << j*(k+1) << endl ;
               break ;
             }
           else if ( work ( k, j*(k+1)+1 ) )
             {
               cout << j*(k+1)+1 << endl ;
               break ;
             }
          }
       }
    return 0 ;
}
