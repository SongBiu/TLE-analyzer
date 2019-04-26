#include<iostream>
using namespace std;

struct man
{
	int c;	//0 good, 1 bad	
	man * next;
	man * prev;
};
man m[30];
int k;

int main()
{
	while(cin>>k)
	{
		if(k==0)
			break;
		for(int i=1;i<=k;i++)
			m[i].c = 0;
		for(int i=k+1;i<=2*k;i++)
			m[i].c = 1;
		int i = 0;
		while(true)
		{
			i++;
			if(i%(2*k)>=1 && i%(2*k)<=k)
				continue;
			bool flag = true;
			for(int j=1;j<=2*k-1;j++)
			{
				m[j].prev = &m[j-1];
				m[j].next = &m[j+1];
			}
			m[1].prev = &m[2*k];
			m[1].next = &m[2];
			m[2*k].next = &m[1];
			m[2*k].prev = &m[2*k-1];
			
			int s = 0, r = 0;
			man * p = &m[1];
			while(s<k)
			{
				r++;
				if(r==i)
				{
					//cout<<"s = "<<s<<endl;
					p->prev->next = p->next;
					p->next->prev = p->prev;
					if(p->c == 0)
						flag = false;
					r = 0;
					s++;
				}
				p = p->next;
			}
			if(flag)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}