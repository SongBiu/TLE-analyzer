#include <stdio.h>
int main()
{  
    int k; 
    int a[15];
    while(1)
    {
        scanf("%d",&k);
        if(k==0)break;
        int m=k+1;
        while(1)
        {         
            int pre=2*k,delc=0;
            int mm=2*k;
            int p=1;
            while(delc<k)
            {
               int nn = m%mm;
               p=(pre+nn)%mm;
               if(p==0) p = mm;
               if(p>k)
               {
                   mm--;
                   pre=p-1;
                   delc++;
               }    
               else break;       
            }
            if(delc == k) break;
           
            m++;
            if(m%(2*k)==1) m = m+k;
            
        }        
        printf("%ld\n",m);
    }    
    
    return 0;
}    