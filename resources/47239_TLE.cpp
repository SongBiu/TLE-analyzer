#include<iostream>
using namespace std;
int k;
int Joseph[14];
int minimalM(){
	if(Joseph[k]!=0) return Joseph[k];
	int N=2*k;
	int people=N;
	int count=0;
	int m=k+1;
	while(1){
	   int M=N+count*N;
	   for(;m<=M;m++){
		  people=N;
	      int a=(m-1)%people;
		  int cnt=k;
		  while(cnt&&a>=k) {
			  a=(a+m-1)%(--people);
			  cnt--;
		  }
		  if(cnt==0) {return m;Joseph[k]=m;}
	   }
	   count++;
	   m=k+1+count*N;
	}
}
int main(){	
	while(cin>>k&&k!=0){
	    int m= minimalM();
		cout<<m<<endl;
	}
	return 0;
}
