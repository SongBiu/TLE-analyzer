#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int k , i , j , left , l;
	bool flag[30] , c;
	while(cin >> k&&k!=0)
	{
		for (i = 1;;i++)
		{
			memset(flag,true,sizeof(flag));
			left = 2*k;
			j = l = 1;
			while(left>k)
			{
				if (j==i)
				{
					left--;
					flag[l] = false;
					j = 0;
				}
				j++;
				do
				{
				   l++;
				   if (l > 2*k) l = 1;
				}while(!flag[l]);
			}
			c = true;
			for (l = 1 ; l <= k ; l++)
			{
				if (!flag[l])
				{
					c = false;
					break;
				}
			}
			if(c)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}