#include<iostream>
using namespace std;

int main(){
	int k;
	int people[30];
	int i,j,count,baddead;
	int m;
	while(1){
		cin>>k;
		if(k==0) break;
		for(m=1;;m++){
			for(i=0;i<2*k;i++)
			   people[i]=1;
			count=0;j=0; baddead=0;
			while(1){
				if(people[j]==0){
					j=(j+1)%(2*k);
					continue;
				}
				count++;
				if(count==m){
					people[j]=0;
					if(j>=0&&j<k) break;
					else{
						if(k<=j&&j<=2*k-1) baddead++;
						if(baddead==k) break;
					}
					count=0;
					j=(j+1)%(2*k);
				}
				else j=(j+1)%(2*k);
			}
			if(baddead==k&&people[0]!=0) { cout<<m<<endl;  break;}
		}
	}
	return 0;
}
