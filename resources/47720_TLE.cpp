#include <cstdio>
int k;
bool gg(int m){
    int size=k*2,i=-1;
    while(true){
        i=(i+m)%size;
        if(i--<k) return true;
        else {
            if(--size==k) return false;
        }
    }
}
int main(){
    while(scanf("%d",&k),k){
        int m=k;
        while(gg(++m));
        printf("%d\n", m);
    }
}