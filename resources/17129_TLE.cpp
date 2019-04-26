#include<stdio.h>
#include<string.h>

int k,a[26],temp[26],store[14];
int m;

int main()
{
    int i,j;
    memset(store,0,sizeof(store));
    while(scanf("%d",&k) && k){
        if(store[k]!=0)printf("%d\n",store[k]);
        else{
        for(i = 0;i < 2*k;++i){
            a[i] = i+1;
        }
        i = 1;
        while(1){
            if(i%(k+1) || (i-1)%(k+1)){
            for(j = 0;j < 2*k;++j){
                temp[j] = a[j];
            }
            int c = 1;
            int p = 0;
            j = 0;
            while(p < k){
                if(i<=k)break;
                if(temp[j] && c==i){
                    if(j < k)break;
                    p++;
                    temp[j] = 0;
                    c = 1;
                }
                else if(temp[j] && c!=i){
                    c++;
                }
                j++;
                if(j==2*k)j = 0;
            }
            if(p == k)break;
        }
            i++;
        }
        store[k] = i;
        printf("%d\n",i);
    }
    }
    return 0;
}
