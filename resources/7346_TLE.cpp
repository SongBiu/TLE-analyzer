// Joseph1012.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

//针对n个人m报数，求出第nRing轮杀掉的人的原始序号
int GetOriginNum(int n, int m, int nRing) 
{
	int nNo = (m-1) % (n-nRing);
	for (int i=nRing; i>0; i--)
	{
		nNo = (nNo%(n-i) + m % (n-i+1)) % (n-i+1) ;
	}

	return nNo;
}
/*
int nRes[14] = 
{
0,
2, 
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881};
*/
int main(int argc, char* argv[])
{
	
/*	int n,m;
 	cin>>n>>m;
 	for (int i=0; i<n; i++)
 	{
 		cout<<GetOriginNum(n,m,i)<<endl;
 	}
*/
	
	int k;
	while (cin>>k && k!=0)
	{
 		int nFactorial = 1;
 		for (int t=1; t<=2*k; t++)
 		{
 			nFactorial *= t;
 		}
 		if (nFactorial<0)
 		{
 			nFactorial = 3000000; //仅仅可以到13，但还是会超时的
 		}
 		int nResult = 0;
 		for (int m=1; m<=nFactorial; m++)
 		{
 			bool flag = true;
 			int nNo;
 			for (int r=0; r<k; r++)
 			{
				nNo = GetOriginNum(2*k, m, r);
 				if (nNo < k)
 				{
 					flag = false;
 					break;
 				}
 			}
 			if (flag)
 			{
 				nResult = m;
 				break;
 			}
 		}
		
		cout << nResult <<endl;

		//cout<<nRes[k]<<endl;
	}

	return 0;
}

