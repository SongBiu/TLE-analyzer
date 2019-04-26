#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NUM 26
int aLoop[MAX_NUM+1];
int findMin(int k){
	int i,j,m=0,n=2*k,nPtr,nCounted;
	bool found;
	while(true){
		m++;
		found=true;
		for(i=0;i<n;i++)
			aLoop[i]=i;
		nPtr=0;
		nCounted=n;
		for(i=0;i<k;i++){
			nPtr=(nPtr+m-1)%nCounted;
			if(aLoop[nPtr]<k){
				found=false;
				break;
			}
			for(j=nPtr;j<nCounted-1;j++)
				aLoop[j]++;
			nCounted--;
		}
		if(found)
			break;
	}
	return m;
}
int main()
{
	int k;
	while(true){
		scanf("%d",&k);
		if(k==0)
			break;
		printf("%d\n",findMin(k));
	}
	return 0;
}
