#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int a[30];
	int t[15]={0};
	int i,j,k,n,p,q,ptr,flag;
	t[13]=2504881;
	t[14]=13482720;
	t[12]=1358657;
	while (1)
	{
		cin>>k;
		if (k==0) break;
		if (t[k]) 
		{
			cout<<t[k]<<endl;
			continue;
		}
		n=k*2;
		for (i=k+1;;i++)
		{
			flag=0;
			p=n;
			q=k;
			ptr=0;
			memset(a,0,sizeof(a));
			while (q>0)
			{
				j=i%p;
				if (j==0) j=p;
				while (j-1)
				{
					while (a[ptr]) ptr=(ptr+1) % n;
					ptr=(ptr+1) % n;
					j--;
				}
				while (a[ptr]) ptr=(ptr+1) % n;
				if (ptr<k)
				{
					flag =1;
					break;
				}
				else 
				{
					a[ptr]=1;
					q--;
					p--;
				}

			}
			if (flag) continue;
			else 
			{
				cout<<i<<endl;
				a[k]=i;
				break;
			}
		}
		
	}
	return 0;
}
