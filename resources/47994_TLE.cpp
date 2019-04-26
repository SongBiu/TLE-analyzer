#include<stdio.h>
#include<iostream>

#include<string.h>
using namespace std;

int main()
{
int k;

while(cin>>k&&k)
{
	int good_exe=0;
	int m=k+1;
	
	while(1){
		//int tmp_exec[29]={0};
		int num=0;
		for(int i=0;i<k;i++)
		{
			num+=m;
			num=num%(2*k-i);//被杀的序号
			if(num>=1&&num<=k)//杀了好人
			{
				good_exe=1;
				break;
			}
			if(num==0)
				num=2*k-i;
			num--;
		}
		if(good_exe==0) break;
		m++;
		good_exe=0;
}
	cout<<m<<endl;
}

return 0;

}