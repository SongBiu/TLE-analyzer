#include <stdio.h>

class Queue{
public:
	int data[65536];
	int len;
	int q;
	int cur;
	Queue(int k,int qq):q(qq),cur(0){
		int i=0;
		for(;i<k;++i){
			data[i]=1;
			data[i+k]=0;
		}
		len=(k<<1);
	}

	int remove(){
		cur=(cur+q-1)%len;
		return remove(cur);
	}

	int remove(int flag){
		int temp=get(flag);
		--len;
		for(int i=flag;i<len;++i){
			data[i]=data[i+1];
		}
		return temp;
	}
	int get(int flag){
		return data[flag%len];
	}
};

int main(){
	int k;
	while(1){
		scanf("%d",&k);
		if(0==k) break;
		int helper;
		for(int i=k+1;;++i){
			Queue qe(k,i);
			helper=0;
			while(1){
				if(qe.remove()==0){
					++helper;
				}else{
					break;
				}
			}
			if(helper==k){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}