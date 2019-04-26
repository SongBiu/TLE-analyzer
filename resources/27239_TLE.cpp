#include <iostream>
using namespace std;

int k;

bool fun(int m)
{
	int number = k * 2; //剩余人的个数，开始时是 2*k个人
	int kild = m %  number;
	if(kild==0)            //如果为0代表报数的是最后一个人，此时number的值没有改变
			kild = number;
	number--;             //杀了一个人
	
	if(kild <=k)
		return false;   //错杀了好人
	
	int i;            //循环变量，杀人的次数
	for(i=0;i<k-1;i++)
	{
		kild = (kild  + m - 1) %number;		
		if(kild==0)
			kild = number;
		if(kild <= k)
			return false;
		
		number--;
	}
	
	return true;
}


int  main()
{
	cin>>k;
	
	while(k)
	{
		int m = k + 1;
		
		while(1)
		{
			if(fun(m))
			{
				cout<<m<<endl;
				break;
			}
			
			if(fun(m+1))
			{
				cout<<m+1<<endl;
				break;
			}
			
			m += k+1;
		}
		
		cin>>k;
	}
}