
//http://172.23.154.41/problem?id=1012
//

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <vector>

///////////////////////////////////////////////////////////
//joseph
typedef struct tag_node
{
	int gays_no;
	int gays_flag;//1 bad ,0 good gays
}SGayInfo;

typedef std::vector<int> TGayInfoVector;

TGayInfoVector gayinfo; //最多30个人

int total_gays;
int bad_gays;
int good_gays;

int try_do(int m)
{
	int i,j,k;
	int gay;
	//SGayInfo *pGayInfo;
	int bad_killed=0;
	int good_killed=0;

	//初始化
	gayinfo.clear();
	//gayinfo.push_back(0);
	for(i =1;i<=good_gays;i++)
	{
		gay = i;
		gayinfo.push_back(gay);
	}
	for(i =good_gays+1;i<=total_gays;i++)
	{
		gay = i;
		gay |= 0x8000;
		gayinfo.push_back(gay);
	}

	//开始游戏
	TGayInfoVector::iterator it ;
	int size ,start = 1,nn;
	while(1)
	{
		size = gayinfo.size();
		it = gayinfo.begin();
		if(!size)break;
		{
			nn = (start+m-1)%size;
			if(!nn)nn = size;
		
			gay =  gayinfo[nn-1];
			if(gay&0x8000)
			{
				bad_killed++;
			}
			else
			{
				if(bad_killed>=bad_gays)
				{
					return 1;
				}
				break;
			}
			gayinfo.erase(it+nn-1);
			start = nn;
		}
	}

	return 0;
	

}

int try_count(int k)
{
	int i,j;

	total_gays = k+k;
	bad_gays = good_gays =k;

	for(i = k+1;;i++)
	{
		if(try_do(i))return i;
	}
	return 0;
}

int main()
{
	int i,k;

	while(1)
	{
		scanf("%d",&k);
		if(!k)break;
		printf("%d\n",try_count(k));
	}

	return 0;
}
 
