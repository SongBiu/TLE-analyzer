#include<iostream>
#include<memory>
using namespace std;
int main()
{
	unsigned int k,m,i,flag,bad,l,j,p;
	while(cin>>k){
		if(!k){
			break;
		}
		flag=0;
		for(j=1;;j++){
			if(flag){
				break;
			}
			for(p=1;p<=k;p++){
				if(flag){
					break;
				}
				i=j*k+p;
				m=0;
				l=k*2;
				bad=k;
				while(1){
					m=(m+i)%l;
					if(m<=k&&m>0){
						break;
					}
					else{
						bad--;
						if(!bad){
							flag=1;
							break;
						}
						if(m){
							m--;
						}
						else{
							m=l-1;
						}
						l--;
					}
				}
				if(flag){
					cout<<i<<endl;
				}
			}
		}
	}
	return 0;
}