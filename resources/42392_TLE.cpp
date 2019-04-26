#include <stdio.h>
#include <stdlib.h>
int joseph(int k){
	int i,s=0,m;
	
	for(m=k+1;;m++)
	{
		for(i=2*k,s=0;i>k;i--)
		{
			s=(s+m-1)%i;
			if(s<k) break; 
		} 
		if(i==k)
		{
			
			return m;
		}
	
	} 
	return 0;
}

int main(){
	int n;
	while(scanf("%d",&n))
	printf("%d\n",joseph(n));
}