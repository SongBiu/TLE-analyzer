#include<iostream>
using namespace std;
int k;
bool judge(int count);
int main()
{
	int i;
	while(cin>>k&&k){
		for(i=3*k/2;;){
			i++;
			if(judge(i)) break;
		}
		cout<<i<<endl;
	}
	return 0;
}
bool judge(int count)
{
	int num=0,num1=2*k,l=0;
	while(num<k){
		if((count+l)%num1==0){
			num++;num1--;
			l=0;
		}
		else{
			l=(count+l)%num1-1;
			if(l+1<=k) return 0;
			num1--;num++;
		}
	}
	return 1;
}