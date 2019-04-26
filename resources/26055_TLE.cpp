#include <iostream>
using namespace std;
int test(int,int);
int main()
{
	int k;
	while(cin>>k)
	{
		if(k==0)
		{break;}

		for(int m=k+1;;m=m+k+1)
		{
			if(test(k,m))
			{
				cout<<m<<endl;
				break;
			}
			else if(test(k,m+1))
			{
				cout<<m+1<<endl;
				break;
			}
		}
	}
	return 0;
}


int test(int k,int m)
{
	int n=2*k;
	int j=0;
	for(int i=0;i<k;i++)
	{
		j=(j+m-1)%(n-i);
		if(j<k)
			return 0;
	}
	return 1;
}
			
			
		
