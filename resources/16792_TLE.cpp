#include <iostream>
using namespace std;


struct node;
typedef struct node *pnode;
struct node
{
	int n;
	pnode link;
};


int joseph(int n,int m)
{
	if (n==1)
		return 2;
	int i;
	pnode p,q;
	p=new node;
	q=p;
	p->n=1;
	for (i=1;i<=2*n-1;i++)
	{
		p->link=new node;
		p=p->link;
		p->n=i+1;
	}
	p->link=q;
	p=q;
	for (i=1;i<=n;i++)
	{
		int j;
		for (j=2;j<=m-1;j++)
		{
			p=p->link;
		}
		pnode r=p;
		p=p->link;
		r->link=p->link;
		if (p->n>=1&&p->n<=n)
		{
			int j;
			pnode s=q;
			for (j=1;j<=2*n-i;j++)
			{
				s=s->link;
				delete q;
				q=s;
			}
			return 0;
		}
		delete p;
		p=r->link;
	}
	return m;
}


int main()
{
	int a[15];
	int i;
	for (i=1;i<=14;i++)
	{
		int k;
		for (k=2;;k++)
		{
			if (joseph(i,k)!=0)
			{
				a[i]=joseph(i,k);
				break;
			}
		}
	}
	while (1)
	{
		int n;
		cin>>n;
		if (n==0)
			break;
		cout<<a[n]<<endl;
	}
	return 0;
}