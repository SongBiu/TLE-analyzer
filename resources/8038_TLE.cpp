#include<iostream>
using namespace std;
int num[28];
int main()
{
	int k,t,i,l,j;
    while(cin>>k)
	{
    	if(k==0)break;
        int n=2*k;
        for(t=0;;t=t+2)
		{
           for(i=k+1;i<=n;i++)
		   {
	        	int m=t*k+i;int count=n;          //前面的两重循环目的在于试取m的取值；
	        	for(l=0;l<n;l++)num[l]=1; //初始化数组的值为1；
	        	l=-1;
                for(j=0;j<k;)             //剔除后k个人的循环；
				{
				     int x=m;if(m%count!=0)x=m%count;else x=count;
			         for(int c=0;c<x;)        //每剔除一个人要循环m次才能剔除；
					 { 
						 l=(l+1)%n;
			           	 if(num[l]!=0)
						 {
							 c++; 
						 }
					 }
		        	if(l>=k){num[l]=0;count--;j++;}
			        else break;
				}
	            if(j==k){cout<<m<<endl;goto end;}
		   }
		}
end:    
		k=0;
	}
return 0;
}