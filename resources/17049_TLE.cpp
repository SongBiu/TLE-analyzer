#include <iostream>
using namespace std;


int main()
{
	short k;
	bool flag=0;
	while(cin>>k)
	{
		if(k==0)
		return 0;
		for(int i=k+1;flag==0;++i)
		{
			short round=0;
			short current_num=2*k-round;
			int temp2=i%current_num;
			int temp=temp2?temp2:current_num;
			while(1)
			{
				if(temp<=k&&temp>0)
				{
					if(round==k)
					{
						flag=1;
						cout<<i<<endl;
					}
					break;
				}
				++round;
				current_num=2*k-round;
				temp2=(temp+i%current_num-1)%current_num;
				temp=temp2?temp2:current_num;
			}
			if(i%(2*k)==0)
			i=i+k;
		}
		flag=0;
	}
}
