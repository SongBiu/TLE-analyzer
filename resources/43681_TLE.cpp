#include <cstdio>
#include <cstdlib>

int main()
{
	unsigned int k[10010],m,pos,nsize,tried;
	int i=0;
	int j=0;
	while (scanf("%d",&k[i++])!=EOF){
		if(k[i-1]==0)
		    break;
	}
	for(j=0;j<i-1;j++){
		for (m=k[j]+1;;m++) {
			/*try n*/
			tried=0;
			jtry:/*good=[0,k-1],bad=[k,2k-1]*/
			pos=k[j]*2-1;
			for (nsize=k[j]*2;;nsize--){
				pos+=m;
				pos%=nsize;
				if (pos<k[j])
				    break;
				pos--;
			}
			if (nsize==k[j]){
				printf("%d\n",m);
				break;
			}
			else if (!tried){
				tried=1;
				/* tried n+1 */
				m++;
				goto jtry;
			}
		}
	}
	
return 0;
}