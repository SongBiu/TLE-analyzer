#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,k,m;//k个好人
	int result[14]={0};
	while(cin>>k && k!=0)
	{
		if(result[k])//如果前边算过
		{
			printf("%d\n",result[k]);
			continue;
		}
		int victim[14]={0};//每次死的人的编号，编号从0到k-1
		n=k+k;//总人数为2k
		m=k+1;//m最少也得从k+1开始
		for(int i=1;i<=k;i++)//死k个人
		{
			victim[i]=(victim[i-1]+m-1)%(n-i+1);
			//递推公式：victim[i]+m-1为后面的人补上之后，这次报到m的人的新编号
			//n-i为活着的人数，取模是因为到尾之后要从头开始报

			if(victim[i]<k)//如果死了个好人，换下一个m值
			{
				i=0;
				m++;
			}
		}
		printf("%d\n",m);
		victim[k]=m;
	}
	return 0;
}