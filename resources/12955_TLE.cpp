#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int k;
    while( cin>>k && k != 0 )
    {
           int s[30]={0};
           int i,m;
           for( i = 1 ; i <= 2*k ; i++ ){
                if( i > k )  s[i]=0;
                else  s[i]=1;
           }
           int length = 2*k;
           int L[28]={0};
           for( m = k+1 ; ; m++ ){
                int count = 0 ;
                for( i = 0 ; i < k ; i++ ){                  //找的趟数 
                     int a = m %length ;                 //找到的第一个坐标 
                     if( a==0 ) a=length;
                     if( s[a]==1 ) break; 
                     count++;
                     if( count==k ) break; 
                     int j = 1 ;
                     int r;
                     for( r = a+1 ; ; r++ ){
                          int loc = r%length;
                          if( loc==0 ) loc=length;
                          L[j]=s[loc];
                          j++;
                          if(j==length) break;
                     }
                     length = length - 1;
                     for( r = 1 ; r <= length ; r++ ){
                          s[r]=L[r];
                     }
                }
                if( count==k ) break;
           }
           cout<<m<<endl;
    } 
    system("PAUSE");
    return EXIT_SUCCESS;
}
