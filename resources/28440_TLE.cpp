#include<stdio.h>

int K;

int main(){
    int i,j,x,ok;
    for(scanf("%d",&K);K>0;scanf("%d",&K)){
    for(i=1;;i++){
        ok=1;
        x=0;
        for(j=0;j<K;j++){
            x=(x+i)%(2*K-j);
            if(x<K){
                ok=0;
                break;
            }
        }
        if(ok){
            printf("%d\n",i+1);
            break;
        }
    }
    }
    return 0;
}
