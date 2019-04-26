#include <iostream>
#include "string.h"
#include <algorithm>
using namespace std;

int a[28];
int biaoji[28];
int xulie[28];

bool Joseph(int m,int n)
{
	memset(biaoji,0,28*4);
	memset(xulie,0,28*4);
	int all = 0;
	int i = 0;
    int curr = 0;
	while(all < n)
	{
		while(curr < m)
		{
			if(biaoji[i] == 0)
			{
				i = (i+1)%n;
				curr++;
			}
			else
			{
				i = (i+1)%n;
			}
		}
		i = (i+n-1)%n;
		biaoji[i] = 1;
		xulie[all] = a[i]+1;
		all++;
		curr = 0;
	}

	for(i = 0 ; i < n/2 ; i++)
	{
		if(xulie[i] <= n/2)
			return false;
	}


	return true;
}


int main(void)
{

    int k;
	cin>>k;
	int i;
	int j;
	while(k > 0)
	{
	   memset(a,0,28*4);
	   memset(biaoji,0,28*4);
	   for(i = 0 ; i < 2*k ; i++)
	   {
		   a[i] = i;
	   }
	  
	   for(j = 1 ; j <= 100 ; j++)
	   {   
		  if(Joseph(j,2*k))
		  {
			  cout<<j<<endl;
		      break;
		  }
		  
	   }
	 
      cin >>k;

	}
	return 0;
}