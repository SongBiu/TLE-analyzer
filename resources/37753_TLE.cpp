#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int K,M;vector<int> C;
int main(){
	int i,j,z;
	while(1){
		scanf("%d",&K);
		if(K==0)break;
		if(K==1){printf("2\n");continue;}
		M=2;
		while(1){
			C.clear();
			for(i=1;i<=2*K;i++)C.push_back(i);
		    z=0;
		    for(i=1;i<=K;i++){
			    z=(z+M-1)%C.size();
			    if(C[z]<=K)break;
			    for(j=z;j<C.size()-1;j++)C[j]=C[j+1];
				C.pop_back();
				}
			if(i>K)break;
			M++;
			}
		printf("%d\n",M);
		}
	return 0;
}
