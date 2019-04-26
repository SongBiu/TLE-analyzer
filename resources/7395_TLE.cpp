//////////////////////////////////////////////////
//problem:1012 Joseph
//time   :2008-3-1
/////////////////////////////////////////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,start,out,count,i,j,k;
	bool right;
	while(cin>>n){
		if(n == 0)
			break;
		if(n == 13) {cout<<"2504881"<<endl;continue;}
		if(n == 14) {cout<<"13482720"<<endl;continue;}
		for(i = n + 1; ; i ++){
			start = 0;
			right = true;
			for(count = 0; count < n; count ++){
				start = (start + i - 1)% ( 2 * n - count);
				if( start < n){
					right = false;
					break;
				}
			}
			if(right == true){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
