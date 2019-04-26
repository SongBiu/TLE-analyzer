#include<iostream>
using namespace std;
int main()
{
	int n,m;
	while(cin >> n&&n!=0)
	{
		for(m = n+1;;m++)
		{
			if((m-1) % (2*n) == 0)
				m += n;
			int i,cur=0;
			for(i = 0;i < n;i ++)
			{
				int s = 0;
				s = (cur+m)%(2*n-i);
				if(s == 0)s = 2*n-i;
				//cout << m << " " << s << " "<< endl;
				cur = s-1;
				if(s <= n)
					break;
			}
			if(i == n)
				break;
		}

		cout << m << endl;
	}
}