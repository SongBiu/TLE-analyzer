#include<iostream>
using namespace std;
const int max_n=28;
bool joseph(int,int);
int main()
{
	int m,k;
	cin>>k;
	while(k!=0)
	{
		m=1;
		while(joseph(m,k))
		{
			m++;
		}
		cout<<m<<endl;
		cin>>k;
	}
	return 0;
}
bool joseph(int m_,int k_ )
{
	int remain[max_n]={0};

	int i,j;
	int lastnum=k_;
	for(i=1,j=0;lastnum>0;++i,++j)
	{
		while(remain[j]==1)
		{
			j++;
		}
		if(j>=2*k_)
			j=0;
		if(i==m_)
		{
//			cout<<lastnum<<" ";
			if(j>=k_)//这里条件弄错了会导致死循环
			{
				--lastnum;
//				cout<<lastnum<<" ";
				remain[j]=1;
			}
			else
			{
//				for(int l=0;l<2*k_;l++)
//					cout<<remain[l]<<" ";
//				cout<<m_<<endl;
				return true;//尚未满足条件
//				for(int l=0;l<2*k_;l++)
//					cout<<remain_[l]<<endl;
				//使用cout测试注意其位置,在return之前
			}
			i=0;//在考虑模拟类型的题目时,千万要注意初始形态和终止形态,最好能够把它写下来以防疏忽
		}
	}
	return false;//满足跳出条件
}
