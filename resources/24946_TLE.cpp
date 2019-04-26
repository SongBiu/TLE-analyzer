#include <iostream>
#include <queue>
using namespace std;
int main()
{
	queue<int> minm;
	short k;	
while(cin>>k)
{
	if(k==0)break;
	for (int m=k+1;;m++)
	{
		int rem=1;
		int i;
		for (i=0;i<k;i++)
		{	
		rem=(m-1+rem)%(2*k-i);
		if(rem==0)
			rem=2*k-i;
		if(rem<=k)
			break;
		}
		if(i==k)
		{
			minm.push(m);
			break;
		}	
	}	
}
for (int n=minm.size();n>0;n--)
	{
		cout<<minm.front()<<endl;
		minm.pop();
	}
return 0;
}
