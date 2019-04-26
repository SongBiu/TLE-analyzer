#include<iostream>
using namespace std;
bool check(int i,int j)
{
        int start=1;
        int x;
        int leng=2*i;
        for(x=1;x<=i;x++)
        {
                start=(start+j-1)%leng;
                if(start==0) start=1;//leng;
                leng--;
                if(start<=i) return false;
              //  if(start>leng) start=1;
        }
        return true;
}
int main()
{
    int a[15];
        int i,j;
        for(i=1;i<14;i++)
        {
                for(j=i+1;;j++)
                {
                        if(check(i,j))
                        {
                                a[i]=j;
                                break;
                        }
                }
        }
        cin>>i;
        while(i!=0)
        {
                cout<<a[i]<<endl;
                cin>>i;
        }
}
	

				
