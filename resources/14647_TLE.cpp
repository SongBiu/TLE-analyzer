#include <stdio.h>
int judge(int m,int k)
{
	int i,j,t,value=1,guy[30];
	for (i=0;i<k*2;i++)
		guy[i]=i;
	for (i=0,t=0;i<k;i++){
		t=(t+m-1)%(k*2-i);
		if (t<k){
			value=0;
			break;
		}
		else{
			for (j=t;j<k*2-i-1;j++)
				guy[j]=guy[j+1];
		}
	}
	return value;
}
int main()
{
	int k,m;
	while (1){
		scanf("%d",&k);
		if (k==0)
			break;
		for (m=k+1;!judge(m,k);m++)
			;
		printf("%d\n",m);
	}
	return 0;
}