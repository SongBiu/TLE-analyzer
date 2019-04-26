#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,p,t=0,a[40],cot,m;
    for(;;)
    {
        scanf("%d",&p);
        if(p==0)break;
        for(k=p+1;;k++)
        {
            i=1,t=0;
            for(m=1;m<=p*2;m++)a[m]=1;
            for(j=1;t>=0;j++)
            {
                if(j>p)
                {
                    t=1;
                    break;
                }
                cot=0;
                for(;;i++)
                {
                    if(i>2*p)i=1;
                    if(a[i]==1)cot++;
                    if(cot==k)
                    {
                        if(i<=p)t=-1;
                        else a[i]=0;
                        break;
                    }
                }
            }
            if(t==1)break;
        }
        printf("%d\n",k);
    }
    //system("pause");//fuck poj
    return 0;
}