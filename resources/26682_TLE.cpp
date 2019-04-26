#include<iostream>
#include<fstream>
using namespace std;
bool legal(int m,int k){
	int i=0;
	int round=k;
	int p=2*k;
	while(round--){
		i=(i+m-1)%p;
		if(i<k)
			return false;
		p--;
	}
	return true;
}
int main(){
	//ifstream cin("aaa.txt");
	int k,m;
	while(cin>>k && k){
		int t=1;
		while(1){
			m=t*(k+1);
			if(legal(m,k)){
				cout<<m<<endl;
				break;
			}
			m=t*(k+1)+1;
			if(legal(m,k)){
				cout<<m<<endl;
				break;
			}
			t++;
		}
	}
	//system("pause");
	return 0;
}