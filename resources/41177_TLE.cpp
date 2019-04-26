#include <iostream>
using namespace std;


int main()
{
	int k; 
	while (cin>>k&&k)
	{ 	 
		for(int m=k+1;;m++)
		{ 
			bool flag=false;   
			int sum=2*k;    
			for (int j=m;;j+=m-1)     
			{     
				j=j%sum?j%sum:sum; 
				if(j<=k)break;  
				sum--; 
				if(sum==k){
					flag=true; 
					cout<<m<<endl; 
					break;
				}
			}
			if (flag)break; 
		}
	}
	return 0; 
}