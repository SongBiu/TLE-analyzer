#include <iostream>
using namespace std;
int main()
{
  int k;
  int m;
  int j;
  int l;
  for ( cin>>k; k != 0; cin>>k )
    {
      l = 2 * k;
      for ( m = k + 1; l > k; ++m)
	{
	  j = 0;
	  l = 2 * k;
	  for ( j = (m+j-1)%l; j >=k; j = (m+j-1)%l)
	    --l;
	}
      cout<<m-1<<endl;
    };
  return 0;
}