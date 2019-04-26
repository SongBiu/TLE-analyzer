#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	int *person;
	int k,m,j;
	int killnumber;
	cin>>k;
	
	
	int count,i;
	int flag;
	while(k!=0&&k<14)
	{
		person=new int[2*k];
	 m=k+1;
	while(true)
	{
		i=-1;
	count=0;//jishu
	killnumber=0;
	flag=1;//初始化为1表明可以满足题意
  memset(person,0,sizeof(int)*2*k);
 while(killnumber<k)//一定不能有等号 那么循环终止就是傻了k+1个人 此时一定flag--0
	{  
		count++;
		/*for(j=1;j<2*k;j++)
		{
			if(person[(i+j)%(2*k)]==0)//还未出局
			{
				i=(i+j)%(2*k);
				break;
			}
		}//for j*/
  for(j=1;person[(i+j)%(2*k)]==1;j++);
		
				i=(i+j)%(2*k);
		
			if(count==m)
			{   killnumber++;
				person[i]=1;
				if(i+1<=k) //不满足题意
				{  
					flag=0;
					break;
					
				}
				count=0;
			}//ifcount==m
	}//while killnumber<=k
	if(flag==1)  { cout<<m<<endl;break;}
	if(flag==0)
	{
		if(m%k==2)m=m+k-1;
		if(m%k==1) m=m+1;
	}
		
	}//end while true
	cin>>k;
	delete[]person;
	}
	return 0;
}

