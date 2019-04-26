#include<iostream>
using namespace std;
int k;
int k1;
int b[100000];
int bb[100000];
int nn;
int main()
{
	nn=0;
	while(cin>>bb[nn]&&bb[nn])
	{
		++nn;
	}
		
	for(int kp=0;kp<nn;kp++)
	{
		    k=bb[kp];
			int k1=2*k;
			int *a=new int[k1+1];
			for(int i=1;i<=k;i++)
			{
				a[i]=1;
			}
			for(int i=k+1;i<=k1;i++)
			{
				a[i]=0;
			}
			int ii=k+1;
P:
			int begin=0;

			int i1=0;
			int num=k1;
			int k2=k1;
			while(1)
			{
				i1=(ii+begin)%k2;
				if(i1==0)
					i1=k2;
				if(a[i1]==0)
				{
					k2--;
					begin=i1-1;
					num--;
				}
				else
				{
					ii++;
					goto P;
				}
				if(num==k)
					break;

			}
			b[k]=ii;
	}
	for(int c=0;c<nn;c++)
		cout<<b[bb[c]]<<endl;

		return 0;
}