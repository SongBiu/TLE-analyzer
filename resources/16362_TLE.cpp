#include"stdio.h"
int main()
{ int a[27], k, p0, p, p1, i;
   int b[4]={93313,459901,1358657,2501881};
  while(scanf("%d",&k)&&k)
  { if(k<10)
  {
	  p0=k;
     L:  p0++;       
		 if(p0%(2*k)>=1&&p0%(2*k)<=k)
		 { p0+=k-1; goto L; } 
         p=p0%(2*k); 
         if(p==0)
           p=2*k;
		 
	 for(i=1;i<=2*k;i++)
       a[i]=i;
         a[p]=0; i=1;
         
        while(k-i)
		{  p1=p0;
           while(p1--)
		   { 
             if(p>=2*k)  p%=(2*k);
             if(a[++p]==0) p1++;
		   }
             if( a[p]>=1 && a[p]<=k )  goto L;
             else
			 { a[p]=0; i++; }
		}  
  } 
  else p0=b[k-10];
     printf("%d\n",p0);
  }
  return 0;
}