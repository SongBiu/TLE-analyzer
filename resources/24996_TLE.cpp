#include<iostream>
using namespace std;
bool Fun(int k, int m){
	int i=0;
    int len=2*k;
    while(len>k){
		i=(i+m-1)%len;
		if(i<k)	return false;  
		len--;
    }
    return true;
}
int GetAns(int k)
{
	int i = k+1;
	while(1){
		if(Fun(k,i)) return i;
		if(Fun(k,i+1)) return i+1;
		i += k+1;
	}
	cout<<"Not Found!\n";
	return 0;
}
int main(){
	int k;
	while(cin>>k && k!=0){
		cout<<GetAns(k)<<endl;
	}
	return 0;
}