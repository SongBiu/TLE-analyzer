#include <stdio.h>
#include <memory.h>

int peo[28];
int mk[14];
int k;
int m;

int main(){
     int cp;
     int lt;
     int num;
    
     memset(mk,-1,sizeof(mk));
     while(scanf("%d",&k),k){
         if(mk[k] == -1){
             num = 0;
             for(m=k+1;;m++){
                 cp=0;
                 memset(peo,0,sizeof(peo));
                 for(num=0;num<=k;){
                     for(lt=0;lt<m;){
                         cp += 1;
                         if(cp>2*k)
                             cp =1;
                         if(peo[cp]==0)
                             lt +=1;
                     }
                     peo[cp] = 1;
                     if(cp >k)
                         num += 1;
                     else
                         break;
                     if(num==k)
                         break;
                 }
                 if(num==k)
                     break; 
             }
             if(num==k){
                 mk[k] = m;
                 printf("%d\n",m);
             }
         }
         else
             printf("%d\n",mk[k]);
     }
}

