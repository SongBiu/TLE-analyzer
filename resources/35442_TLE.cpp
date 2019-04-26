#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

typedef	struct Node
{
	int			 n;
	struct Node *next;
}Node, *PNode;

int ans[13]={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};


int Joseph3(int n, int m)
{
	int f=0;

	for (int i=1; i<=n/2; i++) // Last n/2 of Excuted
	{
		f=(m-1)%(n-i+1);
		for (int j=n-i+1; j<n; j++) // Divide Operation is expensive
			f = (m + f)%(j+1);
		if (f<n/2) return 0;
	}

	return 1;
}



int main()
{
	int n,m;

	cin>>n;
	while (n)
	{
		m=n;
		while (!Joseph3(n<<1, ++m)) ;

		cout<<m<<endl;

		cin>>n;
	}

	return 0;
}

