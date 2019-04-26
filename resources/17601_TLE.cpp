#include<iostream>
using namespace std;
int main()
{
	int count,i,A,k,a[29],C;
	bool p;
	while((cin>>k)&&k){
		C=2;
		A=0;
		count=0;
		p=false;
		memset(a,0,sizeof(a));
		while(!p){
			for(i=1;i<=2*k;i++){
				if(a[i]==0){
					A++;
				}
				else continue;
				if(A==C){
					A=0;
					a[i]=1;
					count++;
					if(count>k&&i<=k){
						cout<<C<<endl;
						p=true;
						break;
					}
					else if(count<=k&&i<=k){
						C++;
						A=0;
						count=0;
						memset(a,0,sizeof(a));
						break;
					}
				}
			}
		}
	}
	return 0;
}

			






