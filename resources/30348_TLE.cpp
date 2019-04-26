
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int used[30];

bool exe(int k, int m)
{
	int n, i, s;
	n = 2*k;
	s = 0;
	for (i = 0; i < k; i++)
	{
		s = (s + m - 1)%(n - i);
		if (s < k) return 0;
	}
	cout << m << endl;
	return 1;
}


int main()
{
	int k;
	while(cin >> k)
	{
		if (k == 0) break;
		for (int i = k+1; ; i += k+1)
		{
			if(exe(k, i)) break;
			if(exe(k, i + 1)) break;
		}
	}
	return 0;
}
/*
#include<stdio.h>
int a[14];
int f(int k,int m)
{	
	int n,i,s;
	n=2*k;
	s=0;
	for(i=0;i<k;i++)
	{		
		s=(s+m-1)%(n-i);
		if(s<k) return 0;//遇到前k轮中有小于k的直接返回0
	}	
	return 1;
}

int main()
{	
	int i,k,n;
	for(k=1;k<=14;k++)
	{	
		i=k+1;
		while(1)
		{	
			if(f(k,i))//t(k+1)的情况
			{		
				a[k]=i;
				break;
			}	
			else if(f(k,i+1))//t(k+1)+1的情况
			{
				a[k]=i+1;
				break;
			}	
			i+=k+1;
		}	
	}	
	while(scanf("%d",&n) && n)	
	{		
		printf("%d/n",a[n]);
	}	
	return 0;
}*/
