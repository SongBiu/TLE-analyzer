#include<iostream>
using namespace std;
int main(){
	int a[15];
	int k;
	a[0]=0;
	while(cin>>k){
		if(k==0)break;
		int n=2*k,m=k+1;		
		for(int i=1;i<=k;i++){
			a[i]=(a[i-1]+m-1)%(n-i+1);
			if(a[i]<k){
				i=0;
				m++;
			}			
		}
		cout<<m<<endl;		
	}
	return 0;
}