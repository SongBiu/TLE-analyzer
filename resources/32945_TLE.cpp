#include<stdio.h>
#include<string.h>
int  josephs(int k,int m)
{
	int n=2*k,s=0,i;
	for(i=1;i<=k;i++)
	{
		s=(s+m-1)%(n-i+1);
		if(s<k)
			return 0;
	}
	return 1;

}
int main()
{
	 int k,m,a[14],i;
	 while(scanf("%d",&k),k)
     {
       for(i=k+1;;i+=k+1)
	   {
         if(josephs(k,i))
		 {
			  a[k]=i;
			  break;
		 }
		 else if(josephs(k,i+1))
		 {
			 a[k]=i+1;
			 break;
		 }
	   }
	   printf("%d\n",a[k]);
	 }
	
}