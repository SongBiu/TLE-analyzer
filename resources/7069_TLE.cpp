//By Philip

#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
	int r,k,s,t,n;
	while(cin>>k)
	{
            if(k==0)
		    break;
	        s=k;
            r=0;
	    
	    for(t=k+1;;t++)
	    {
			s=k;
            r=0;
		    n=t;
               while(s>0)
	       {
				  // cout<<r<<" ";
                 if((r+t)%(k+s)>k)
		 {
                    r=(r+t-1)%(k+s);
					
		            s--;
		 }
				 else if((r+t)%(k+s)==0)
				 {
                    r=0;
					s--;
				 }
		 else
			 break;
	       }
	       if(s==0)
		       break;
	    }
	    cout<<n<<endl;
	}
 return 0;
}

