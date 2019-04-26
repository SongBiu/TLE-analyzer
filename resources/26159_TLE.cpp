#include <cstdlib>
#include <iostream>
//#include <ctime>
using namespace std;

int k, m;

bool solve( int pos, int bad){
     int n = k * 2;
     int i = 0;
     for ( ;i <= k ; i++ ){
         pos = ( pos + m - 1 ) % ( n - i );
//         cout << i << ' '  << m << ' ' << pos;
//         system("pause");
         if ( i == k ) return true;
         if ( pos < k ) { return false ;}
         }
     
     
     
//     if ( bad == 0 ) return true;
//     pos = ( pos + m - 1 ) % ( k + bad );
//     if ( pos < k ) return false;
//     return solve( pos, ( bad - 1 ));
     }

int main(int argc, char *argv[])
{
    int pos;
//    clock_t start, end;
    while( cin >> k && k > 0 && k < 14 ){
//           start = clock();
            m = k;
            pos = 0;
            while( !solve( pos, k) ){
                   m++;
                   }
            cout << m << endl;
//            end = clock();
//            cout << end - start << endl;
            }
    return EXIT_SUCCESS;
}
