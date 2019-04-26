/*
 * joseph.cpp
 *
 *  Created on: 2013-3-10
 *      Author: Salforever
 */
int k,x[16]={};
#include <iostream>
using namespace std;
int judge(int temp)
{
	int num=k*2,dq=-1;
	while (num>=k+1)
	{
		dq=(dq+temp)%num;
		if (dq<=k-1) return 0;
		num--;
		dq--;
	}
	return 1;
}
int main()
{
	int temp;
	cin >> k;
	while (k!=0)
	{
		if (x[k]!=0) cout << x[k] << endl;
		{
			temp=k+1;
			while (!judge(temp))
			{
				temp++;
			}
			if (x[k]==0) x[k]=temp;
			cout << temp << endl;
			cin >> k;
		}
	}
}
