#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{  int i,j,num,t,b;
   int P;
   unsigned long k;
   long M;
   int c[26],a[27];
   
for(P=1;P<14;P++)
 { num=0;
   P*=2;
   memset(c,2,26);
   //char *p=(char*)malloc((P+1)*sizeof(char));/
  for(M=P/2+1;;M++)
 { //M=21370;
  if(M%P<=P/2&&M%P!=0)continue;
  t=1;
  memset(c,0,sizeof(P));
  k=0;

  for(i=1;num!=P/2;i++)
  { if(i%(P+1)==0) i=1;
    if(c[i%(P+1)]=0)
    {k++;
      if(k%M==0)
      {//printf("%d ",i%(P+1));
       if(i%(P+1)<=P/2){t=0;break;}
       num++;c[i%(P+1)]=1;
      }
    }
  }//for(i=


  num=0;
 //printf("\n");
  if(t==1)break;
 }//for(M=)
  a[P]=M;
  
 }//while
 scanf("%d",&b);
 while(b!=0)
 {
	printf("%ld\n",a[b]);
	scanf("%d",&b);
 }

  return 0;
}
