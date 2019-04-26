#include<iostream>
using namespace std;
int main()
{
	int k,i,m,a[50],n,j,f;
	while(cin>>k)
	{
		if(k==0)
			break;

		for(m=k+1;;m++)
		{
			if((m%(k+1)==0) || (m%(k+1)==1))
			{
				memset(a,0,sizeof(a));
				i=0;j=0;n=0;f=0;
				while(n<k)
				{
					j++;
					if(j==2*k+1)
						j=1;
					
					if(a[j]==0)
					{
						i++;
						if(i==m)
						{
							n++;
							a[j]=1;
							i=0;
							if(j<=k&&n<=k)
							{
								f=1;
								break;
							}
						}
					}
				}
				
				if(f==0)
				{
					cout<<m<<endl;
					break;
				}

			}
		}
	}

	return 0;
}

					

				
