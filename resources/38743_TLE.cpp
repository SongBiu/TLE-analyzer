#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int ans[15];

int main(){
	memset(ans,0,sizeof(ans));
	int k;
	cin>>k;
	while(k!=0){
		int kill[15];
		kill[0]=0;
		int m=k+1;
		for(int i=1;i<=k;i++){
			kill[i]=(kill[i-1]+m-1)%(2*k-i+1);
			if(kill[i]<k){
				i=0;
				m++;
			}
		}
		cout<<m<<endl;
		cin>>k;
	}

	return 0;
}