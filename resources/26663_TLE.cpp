#include<iostream>
using namespace std;

struct node
{
	enum property{bad, good};
	property prop;
	int value;
	struct node *next;
};

int popbad(int m, int k)
{
	struct node* start = new struct node[2*k];
	struct node* curr = start;
	struct node* before;
	for(int i = 0; i < k; ++ i)
	{
		curr->value = i;
		//cout<<curr->value<<" ";
		curr->prop = node::good;
		curr->next = &start[(i + 1) % (2 * k)];
		curr = curr->next;
	}
	for(int i = k; i < 2 * k; ++ i)
	{
		curr->value = i;
		//cout<<curr->value<<" ";
		curr->prop = node::bad;
		curr->next = &start[(i + 1) % (2 * k)];
		curr = curr->next;
	}
	//cout<<endl;
	before = &start[2*k-1];
	//cout<<before->value<<endl;
	curr = start;
	int count = 0;
	//cout<<"m = "<<m<<": ";
	while(count < 2 * k)
	{
		for(int i = 0; i < m - 1; ++ i)
		{
			before = before->next;
			curr = curr->next;
		}
		if(curr->prop == node::bad)
		{
			//cout<<curr->value<<"->";
			before->next = curr->next;
			curr = curr->next;
			++ count;
		}
		else
			break;
	}
	//cout<<endl;
	delete start;
	return count;
}

int minM(int k)
{
	
	for(int i = k;; ++ i)
	{
		if(popbad(i,k) == k)
		{
			return i;
		}
	}
}

int main()
{
	int k;
	while(cin>>k)
	{
		if(k == 0)
			break;
		cout<<minM(k)<<endl;
	}
	return 0;
}