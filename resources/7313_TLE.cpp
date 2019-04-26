#include<iostream>
using namespace std;
bool test(int m,int n){
	int i,k;
	m--;
	k=0;
	for(i=2*n;i>n;i--){
		k=(k+m)%i;
		if(k<n) return false;
	}
	return true;
}
		
int main()
{
	int i,n;
	while(cin>>n){
		if(n==0) break;
		for(i=n+1;;i++){
			if(test(i,n)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}